# Created by: Roland van Laar <roland@micite.net>
# $FreeBSD$

PORTNAME=	sqlparse
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	roland@micite.net
COMMENT=	Non-validating SQL parser for Python

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|distutils.core|setuptools|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
