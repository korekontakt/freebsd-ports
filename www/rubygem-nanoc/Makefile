# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nanoc
PORTVERSION=	3.6.11
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Simple but flexible static site generator

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cri>=2.3:${PORTSDIR}/devel/rubygem-cri

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/nanoc

.include <bsd.port.mk>
