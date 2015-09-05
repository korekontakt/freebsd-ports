# $FreeBSD$

PORTNAME=	cwrap
PORTVERSION=	0.20150830
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Advanced automatic wrapper for C functions

LICENSE=	BSD3CLAUSE # guess

USE_GITHUB=	yes
GH_ACCOUNT=	torch
GH_TAGNAME=	6e7d52f

NO_ARCH=	yes
NO_BUILD=	yes
USES=		lua:run uniquefiles:dirs
PLIST_FILES=	%%LUA_MODSHAREDIR%%/${PORTNAME}/cinterface.lua \
		%%LUA_MODSHAREDIR%%/${PORTNAME}/init.lua \
		%%LUA_MODSHAREDIR%%/${PORTNAME}/types.lua
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"*.lua" ${STAGEDIR}${LUA_MODSHAREDIR}/${PORTNAME})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
