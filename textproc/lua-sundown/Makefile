# $FreeBSD$

PORTNAME=	sundown
PORTVERSION=	0.20150907
CATEGORIES=	textproc
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Markdown for Lua via Sundown library

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.md
LICENSE_FILE_MIT=		${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	luarocks-${LUA_VER}:${PORTSDIR}/devel/lua-luarocks
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}ffi>0:${PORTSDIR}/devel/lua-ffi

USE_GITHUB=	yes
GH_ACCOUNT=	torch
GH_PROJECT=	${PORTNAME}-ffi
GH_TAGNAME=	f631a97

USES=		lua shebangfix uniquefiles:dirs
SHEBANG_FILES=	mdcat.lua
SHEBANG_LANG=	lua
lua_OLD_CMD=	/usr/bin/env lua
lua_CMD=	${LOCALBASE}/bin/${LUA_CMD}
UNIQUE_SUFFIX=	${LUA_VER_STR}
UNIQUE_SUFFIX_FILES=	bin/mdcat
MAKE_CMD=	luarocks-${LUA_VER} make
MAKE_FLAGS=	--tree="${STAGEDIR}${PREFIX}"
MAKEFILE=	rocks/sundown-scm-1.rockspec
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-build:
	@${MKDIR} ${STAGEDIR}${PREFIX}

post-build:
	@${RM} -fr ${STAGEDIR}${LUA_LIBDIR}/luarocks

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/libsundown.so
# XXX Don't use luarocks bin wrapper
	${INSTALL_SCRIPT} ${WRKSRC}/mdcat.lua \
		${STAGEDIR}${PREFIX}/bin/mdcat

.include <bsd.port.mk>
