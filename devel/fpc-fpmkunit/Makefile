# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fpmkunit

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal build system unit

USE_FPC=	fcl-process hash paszlib
USE_FPC_RUN=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
