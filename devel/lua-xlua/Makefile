# $FreeBSD$

PORTNAME=	xlua
PORTVERSION=	0.20150828
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Extra Lua functions

LICENSE=	MIT # see init.lua

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}sys>0:${PORTSDIR}/devel/lua-sys \
		${LUA_PKGNAMEPREFIX}torch>0:${PORTSDIR}/math/lua-torch

USE_GITHUB=	yes
GH_ACCOUNT=	torch
GH_TAGNAME=	91a786b

NO_ARCH=	yes
NO_BUILD=	yes
USES=		lua:run uniquefiles:dirs
PLIST_FILES=	%%LUA_MODSHAREDIR%%/${PORTNAME}/OptionParser.lua \
		%%LUA_MODSHAREDIR%%/${PORTNAME}/Profiler.lua \
		%%LUA_MODSHAREDIR%%/${PORTNAME}/init.lua
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"*.lua" ${STAGEDIR}${LUA_MODSHAREDIR}/${PORTNAME})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
