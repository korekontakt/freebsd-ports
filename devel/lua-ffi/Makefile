# $FreeBSD$

PORTNAME=	ffi
DISTVERSION=	1.0-28
DISTVERSIONSUFFIX=	-gabc638c
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Standalone FFI for Lua compatible with LuaJIT

LICENSE=	MIT # see ffi.h

USE_GITHUB=	yes
GH_ACCOUNT=	jmckaskill
GH_PROJECT=	lua${PORTNAME}

USES=		gmake lua uniquefiles:dirs
MAKE_ARGS=	LUA="${LUA_CMD}" LUA_CFLAGS="${CFLAGS} -I${LUA_INCDIR}" \
		SOCFLAGS="${CFLAGS} -fPIC"
PLIST_FILES=	%%LUA_MODLIBDIR%%/${PORTNAME}.so

post-patch:
	@${REINPLACE_CMD} -e 's/-Werror//' ${WRKSRC}/Makefile
# XXX cpow(3) is not implemented on DragonFly and FreeBSD
	@${REINPLACE_CMD} -e '/POWC/d' \
		-e '/cdata_pow/d' \
		${WRKSRC}/ffi.c

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
