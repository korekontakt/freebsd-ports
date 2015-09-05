# $FreeBSD$

PORTNAME=	torch
PORTVERSION=	0.20150819
CATEGORIES=	math
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scientific computing framework for Lua

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt

BUILD_DEPENDS=	${LUA_PKGNAMEPREFIX}cwrap>0:${PORTSDIR}/devel/lua-cwrap
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}paths>0:${PORTSDIR}/devel/lua-paths

USE_GITHUB=	yes
GH_PROJECT=	torch7
GH_TAGNAME=	cf186b7

USES=		cmake lua ninja uniquefiles:dirs
CMAKE_ARGS=	-DLUA_INCDIR="${LUA_INCDIR}" \
		-DLUA_LIBDIR="${LUA_LIBDIR}" \
		-DLUA_BINDIR="${PREFIX}/bin" \
		-DLUADIR="${LUA_MODSHAREDIR}" \
		-DLIBDIR="${LUA_MODLIBDIR}" \
		-DLUA="${LUA_CMD}" \
		-DLUA_VER="${LUA_VER}" \
		-DWITH_BLAS=dummy
PORTDOCS=	*
UNIQUE_PREFIX_FILES=	share/cmake/${PORTNAME}
PLIST_SUB=	PKGBASE=${PKGBASE}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS OPENMP
OPTIONS_RADIO=		BLAS
OPTIONS_RADIO_BLAS=	ATLAS GOTOBLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS OPENMP

BLAS_DESC=		Basic Linear Algebra Subprograms
ATLAS_USES=		blaslapack:atlas
ATLAS_USE=		GCC=yes # XXX blas depends
ATLAS_CMAKE_ON=		-DWITH_BLAS=atlas
GOTOBLAS_DESC=		Goto blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
GOTOBLAS_USE=		GCC=yes # XXX blas depends
GOTOBLAS_CMAKE_ON=	-DWITH_BLAS=goto
NETLIB_USES=		blaslapack:netlib
NETLIB_USE=		GCC=yes # XXX blas depends
NETLIB_CMAKE_ON=	-DWITH_BLAS=generic
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_USE=		GCC=yes # XXX blas depends
OPENBLAS_CMAKE_ON=	-DWITH_BLAS=open

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_OFF=	-DWITH_OPENMP=off

post-patch:
	@${REINPLACE_CMD} -e '/README/d' \
		-e '/doc/s,[^"]*/torch,${DOCSDIR},' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/LINK.*rt/d' \
		${WRKSRC}/lib/TH/CMakeLists.txt

.include <bsd.port.mk>
