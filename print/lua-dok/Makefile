# $FreeBSD$

PORTNAME=	dok
PORTVERSION=	0.20150810
CATEGORIES=	print
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Old Torch documentation system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}sundown>0:${PORTSDIR}/textproc/lua-sundown

USE_GITHUB=	yes
GH_ACCOUNT=	torch
GH_TAGNAME=	cdef0eb

NO_ARCH=	yes
NO_BUILD=	yes
USES=		lua:run uniquefiles:dirs
PLIST_FILES=	%%LUA_MODSHAREDIR%%/${PORTNAME}/init.lua \
		%%LUA_MODSHAREDIR%%/${PORTNAME}/inline.lua

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"*.lua" ${STAGEDIR}${LUA_MODSHAREDIR}/${PORTNAME})

.include <bsd.port.mk>
