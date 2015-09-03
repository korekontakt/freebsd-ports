# $FreeBSD$

PORTNAME=	penlight
PORTVERSION=	1.3.2
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Collection of general purpose libraries for the Lua language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>0:${PORTSDIR}/devel/luafilesystem

USE_GITHUB=	yes
GH_ACCOUNT=	stevedonovan
GH_PROJECT=	Penlight

NO_ARCH=	yes
NO_BUILD=	yes
USES=		lua:run uniquefiles:dirs
PORTEXAMPLES=	*
PORTDOCS=	CONTRIBUTING.md CHANGES.md README.md manual

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

TEST_BUILD_DEPENDS=	${RUN_DEPENDS}

pre-install-TEST-on:
	(cd ${WRKSRC} && HOME="${WRKDIR}" \
		LUA_PATH="$$PWD/lua/?/init.lua;$$PWD/lua/?.lua;\
		;$$(${LUA_CMD} -e 'print(package.path)')" \
		${LUA_CMD} run.lua)

do-install:
	(cd ${WRKSRC}/lua && ${COPYTREE_SHARE} \
		"pl" ${STAGEDIR}${LUA_MODSHAREDIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
		"${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS:Nmanual}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${PORTDOCS:Mmanual}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
