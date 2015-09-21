# $FreeBSD$

PORTNAME=	trepl
PORTVERSION=	0.20150829
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Embedabble, Lua-only REPL for Torch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	luarocks-${LUA_VER}:${PORTSDIR}/devel/lua-luarocks
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}paths>0:${PORTSDIR}/devel/lua-paths \
		${LUA_PKGNAMEPREFIX}penlight>0:${PORTSDIR}/devel/lua-penlight \
		${LUA_PKGNAMEPREFIX}sys>0:${PORTSDIR}/devel/lua-sys \
		${LUA_PKGNAMEPREFIX}xlua>0:${PORTSDIR}/devel/lua-xlua \
		${LUA_PKGNAMEPREFIX}torch>0:${PORTSDIR}/math/lua-torch \
		${LUA_PKGNAMEPREFIX}dok>0:${PORTSDIR}/print/lua-dok

USE_GITHUB=	yes
GH_ACCOUNT=	torch
GH_TAGNAME=	9eb1b97

USES=		lua readline shebangfix uniquefiles:dirs
SHEBANG_FILES=	th
SHEBANG_LANG=	lua
lua_OLD_CMD=	/usr/bin/env luajit
lua_CMD=	${LOCALBASE}/bin/${LUA_CMD}
UNIQUE_SUFFIX=	${LUA_VER_STR}
UNIQUE_SUFFIX_FILES=	bin/th
MAKE_CMD=	luarocks-${LUA_VER} make
MAKE_FLAGS=	--tree="${STAGEDIR}${PREFIX}"
MAKEFILE=	trepl-scm-1.rockspec
CFLAGS+=	${CPPFLAGS} # readline
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
# XXX luarocks registry not supported yet
	@${REINPLACE_CMD} -e '/dependencies/,/}/d' ${WRKSRC}/${MAKEFILE}

pre-build:
	@${MKDIR} ${STAGEDIR}${PREFIX}

post-build:
	@${RM} -fr ${STAGEDIR}${LUA_LIBDIR}/luarocks

do-install:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/readline.so
# XXX Don't use luarocks bin wrapper
	${INSTALL_SCRIPT} ${WRKSRC}/th ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
