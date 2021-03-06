# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wine
DISTVERSION=	1.7.51
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Source \
		http://ibiblio.org/pub/linux/system/emulators/wine/
PKGNAMESUFFIX?=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	gerald@FreeBSD.org
COMMENT?=	Microsoft Windows compatibility environment

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		prelink:${PORTSDIR}/sysutils/prelink
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

CONFLICTS_INSTALL=	wine-[0-9]* wine-staging-[0-9]* i386-wine-[0-9]* \
			i386-wine-staging-[0-9]* i386-wine-devel-[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --disable-tests \
		--without-alsa --without-capi --without-dbus \
		--without-gettextpo \
		--without-gphoto --without-gsm --without-gstreamer \
		--without-opencl \
		--without-osmesa \
		--with-oss \
		--without-sane \
		--without-tiff \
		--without-xinerama
CONFIGURE_ENV=	CPPBIN="${CPP}" FLEX="${LOCALBASE}/bin/flex"
WINELIBDIR?=	${PREFIX}/lib
.if !defined(USE_LDCONFIG32)
USE_LDCONFIG=	${WINELIBDIR} ${WINELIBDIR}/wine
.endif
ONLY_FOR_ARCHS=	i386 amd64
USES=		bison compiler:c11 desktop-file-utils gmake shebangfix tar:bzip2
SHEBANG_FILES=	tools/make_requests tools/winemaker \
		tools/winedump/function_grep.pl

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDATA=	l_intl.nls wine.inf

OPTIONS_DEFINE=	CUPS DOCS DOSBOX GNUTLS HAL LDAP LIBXSLT MPG123 OPENAL STAGING V4L WINEMAKER X11 GECKO MONO
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

STAGING_DESC=	Include the Wine Staging patchset
DOSBOX_DESC=	Use DOSBox to run MS-DOS programs
LIBXSLT_DESC=	Use libxslt (only used by msxml3.dll)
WINEMAKER_DESC=	Fully support winemaker (requires Perl)
GECKO_DESC=	Bundle Gecko MSI package for Wine
MONO_DESC=	Bundle Mono MSI package for Wine

CUPS_CONFIGURE_WITH=	cups
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

DOSBOX_RUN_DEPENDS=	dosbox:${PORTSDIR}/emulators/dosbox

GECKO_RUN_DEPENDS=	${DATADIR}/gecko/wine_gecko-2.40-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

HAL_CONFIGURE_WITH=	hal
HAL_LIB_DEPENDS=	libhal.so:${PORTSDIR}/sysutils/hal

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LIBXSLT_CONFIGURE_WITH=	xslt
LIBXSLT_LIB_DEPENDS=	libxslt.so:${PORTSDIR}/textproc/libxslt

MONO_RUN_DEPENDS=	${DATADIR}/mono/wine-mono-4.5.6.msi:${PORTSDIR}/emulators/wine-mono-devel

MPG123_CONFIGURE_WITH=	mpg123
MPG123_LIB_DEPENDS=	libmpg123.so:${PORTSDIR}/audio/mpg123

OPENAL_CONFIGURE_WITH=	openal
OPENAL_USES=		openal

V4L_CONFIGURE_WITH=	v4l
V4L_LIB_DEPENDS=	libv4l1.so:${PORTSDIR}/multimedia/libv4l

WINEMAKER_RUN_DEPENDS=	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML

X11_CONFIGURE_WITH=	x cms fontconfig freetype glu jpeg opengl png xinput2 xrandr xrender
X11_USES=		jpeg
X11_USE=		GL=glu XORG=xcomposite,xcursor,xi,xrandr,xrender
X11_LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
			libfreetype.so:${PORTSDIR}/print/freetype2 \
			liblcms2.so:${PORTSDIR}/graphics/lcms2 \
			libpng.so:${PORTSDIR}/graphics/png

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
# Wine is composed of three parts:
#  - wine (aka this port) is the 32-bit component and runs 32-bit programs (on FreeBSD/i386)
#  - wine64 (aka this part of this port) is the 64-bit component and runs 64-bit programs
#    (on FreeBSD/amd64)
#  - wow64 (a subset of emulators/i386-wine-devel) is a part of the 64-bit component that runs
#    32-bit programs (on FreeBSD/amd64)
# We also currently have:
#  - "wine32" (aka emulators/i386-wine-devel) is the 32-bit component and runs 32-bit programs
#    (on FreeBSD/amd64).  This will be superseded by wow64.

# --libdir is required since Wine defaults to "${PREFIX}/lib64" on amd64.
CONFIGURE_ARGS+=	--enable-win64 --libdir=${PREFIX}/lib
PLIST_SUB+=		WINE32="@comment " WINE64=""

.if ${CHOSEN_COMPILER_TYPE} == clang
CPPFLAGS+=		-D__builtin_ms_va_list=__builtin_va_list \
			-D__builtin_ms_va_start=__builtin_va_start \
			-D__builtin_ms_va_end=__builtin_va_end \
			-D__builtin_ms_va_copy=__builtin_va_copy
.endif

# Wine assumes a WoW64 package is available however WoW64 is not yet available on FreeBSD.
post-patch:
	${REINPLACE_CMD} 's|/wine|/wine64|g' ${WRKSRC}/tools/wineapploader.in

.else
PLIST_SUB+=		WINE32="" WINE64="@comment "
.endif

.if ${PORT_OPTIONS:MSTAGING}
MASTER_SITES+=	https://github.com/compholio/wine-compholio-daily/archive/:cho
COMP_DIST=	v${DISTVERSION}.tar.gz
DISTFILES+=	${COMP_DIST}:cho

EXTRACT_DEPENDS=bash:${PORTSDIR}/shells/bash \
		git:${PORTSDIR}/devel/git \
		${AUTOCONF_DEPENDS}

# Fix build on FreeBSD 8.4 and 9.3 (false positive: powl)
CONFIGURE_ENV+=	ac_cv_have_powl=no
CONFIGURE_ARGS+=--without-pulse
USE_AUTOTOOLS=	autoconf

post-extract: fix-shebang
	cd ${WRKSRC} && ${TAR} xf ${DISTDIR}/${COMP_DIST} --strip-components 1
	cd ${WRKSRC} && bash ./patches/patchinstall.sh --backend=patch DESTDIR=${WRKSRC} --all
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend

post-install:
	@${MV} -f ${STAGEDIR}${WINELIBDIR}/libwine.so.1.0 \
	          ${STAGEDIR}${WINELIBDIR}/libwine.so.1
	@${LN} -sf libwine.so.1 ${STAGEDIR}/${WINELIBDIR}/libwine.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README ANNOUNCE AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/winedbg/README ${STAGEDIR}${DOCSDIR}/README.winedbg
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${STAGEDIR}${DOCSDIR}/README.winedump

.include <bsd.port.post.mk>
