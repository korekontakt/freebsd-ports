# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	cuetools
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for working with CUE and TOC files

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes

PORTDOCS=	README
PORTEXAMPLES=	cuetag.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extras/cuetag.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
