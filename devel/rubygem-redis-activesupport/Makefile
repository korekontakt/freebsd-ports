# $FreeBSD$

PORTNAME=	redis-activesupport
PORTVERSION=	4.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis store for ActiveSupport::Cache

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=3:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-redis-store>=1.1.0:${PORTSDIR}/devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
