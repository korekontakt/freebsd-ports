# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	libxml2
PORTVERSION=	2.7.6
PORTREVISION=	4
CATEGORIES=	textproc linux
MASTER_SITES=	CENTOS_LINUX_UPDATES

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library providing XML and HTML support (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-libxml2-[0-9]* linux-f8-libxml2-[0-9]*

USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	17.el6_6.1
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS ChangeLog.gz Copyright NEWS README TODO

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
