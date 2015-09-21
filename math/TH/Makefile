# $FreeBSD$

PORTNAME=	TH
PORTVERSION=	0.20150819
CATEGORIES=	math

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Low-level tensor library for Torch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC:H:H}/COPYRIGHT.txt

USE_GITHUB=	yes
GH_ACCOUNT=	torch
GH_PROJECT=	torch7
GH_TAGNAME=	cf186b7

USES=		cmake ninja
CMAKE_ARGS=	-DWITH_BLAS=dummy
WRKSRC_SUBDIR=	lib/${PORTNAME}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		OPENMP
OPTIONS_RADIO=		BLAS
OPTIONS_RADIO_BLAS=	ATLAS GOTOBLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS OPENMP

BLAS_DESC=		Basic Linear Algebra Subprograms
ATLAS_USES=		blaslapack:atlas
ATLAS_USE=		GCC=yes # XXX blas depends
ATLAS_CMAKE_ON=		-DWITH_BLAS=atlas
GOTOBLAS_DESC=		Goto blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
GOTOBLAS_USE=		GCC=yes # XXX blas depends
GOTOBLAS_CMAKE_ON=	-DWITH_BLAS=goto
NETLIB_USES=		blaslapack:netlib
NETLIB_USE=		GCC=yes # XXX blas depends
NETLIB_CMAKE_ON=	-DWITH_BLAS=generic
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_USE=		GCC=yes # XXX blas depends
OPENBLAS_CMAKE_ON=	-DWITH_BLAS=open

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_OFF=	-DWITH_OPENMP=off

post-patch:
	@${REINPLACE_CMD} -e '/LINK.*rt/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
