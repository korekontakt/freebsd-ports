# Created by: Balwinder S Dheeman <bdheeman@gmail.com>
# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.12.13
PORTREVISION=	11
CATEGORIES=	devel ipv6
MASTER_SITES=	GNU/non-gnu/${PORTNAME}/source/feature/${PORTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdheeman@gmail.com
COMMENT=	IPv6 enabled cvs.  You can use IPv6 connection when using pserver

CONFLICTS=	cvsnt-[12]* cvs+ipv6-[12]*

USES=		makeinfo tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --without-gssapi \
		--with-editor="vi" \
		--with-tmpdir="/tmp"

INFO=		cvs cvsclient

CVS_SITE?=	:pserver:anoncvs@anoncvs.jp.FreeBSD.org:/home/ncvs
CVS_VER?=	v${PORTVERSION:S//_/g}

post-patch:
	${REINPLACE_CMD} 's/${PORTVERSION:S/./\./g}/&-devel/g' \
		${WRKSRC}/configure
	@${CP} ${FILESDIR}/missing ${WRKSRC}

generate-patch:
	cvs -R -d ${CVS_SITE} rdiff -u -r ${CVS_VER} -r HEAD \
	  src/contrib/cvs \
	| ${SED} \
	  -e 's,^\+\+\+ src/contrib/cvs/,+++ ,' \
	  -e 's,^Index: src/contrib/cvs/,Index: ,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  > ${FILESDIR}/patch-freebsdlocal
	cvs -R -d ${CVS_SITE} rdiff -u -D 1999-12-01 -r HEAD \
	  gnu/usr.bin/cvs/cvs/prepend_args.c \
	  gnu/usr.bin/cvs/cvs/prepend_args.h \
	| ${SED} \
	  -e 's,^\+\+\+ src/gnu/usr.bin/cvs/cvs/,+++ src/,' \
	  -e 's,^Index: src/gnu/usr.bin/cvs/cvs/,Index: src/,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  >> ${FILESDIR}/patch-freebsdlocal

.include <bsd.port.mk>
