# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	debugger-xml
PORTVERSION=	0.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML interface for rubygem-debugger

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder32>=2.0.0:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-byebug>=0:${PORTSDIR}/devel/rubygem-byebug

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rdebug-ide bin/rdebug-vim

.include <bsd.port.mk>
