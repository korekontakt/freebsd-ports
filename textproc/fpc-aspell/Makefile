# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	textproc lang
PKGNAMESUFFIX=	-aspell

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Interface to aspell spelling checker

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	ASPELL
OPTIONS_DEFAULT=	ASPELL

.include "${MASTERDIR}/Makefile"
