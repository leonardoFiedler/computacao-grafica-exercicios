/// \file mathdef.h
/// \brief Header file for RAS class "MathDef".
/// \version $Revision: 0 $

#ifndef RAS_MATHDEF_H
#define RAS_MATHDEF_H

//#include <point4d.h>

/// \namespace VART
/// \brief V-ART namespace;
///
/// All RAS classes and variables are declared inside this namespace.
namespace RAS {
#ifndef RAS_RAD_TO_DEG
    #define RAS_RAD_TO_DEG 57.295779513
#endif
#ifndef RAS_DEG_TO_RAD
    #define RAS_DEG_TO_RAD 0.017453292519943295769236907684886
#endif

//#ifndef RAS_MAX_NUMBER
//    #define RAS_MAX_NUMBER 999999999
//#endif

//    struct S3_P4D               { VART::Point4D p0, p1, p2; };
//    struct sSegment_Point4D     { VART::Point4D   P0; VART::Point4D   P1; };
//    typedef sSegment_Point4D    Segment_Point4D;
//    typedef VART::Point4D       Vector4D; //TODO: [D] acho que poderia usar Point4D direto, testar.

//    struct slope
//    {
//        double angle;
//        double deltaX;
//        double deltaZ;
//        double scaleFactor;
//    };

//    class MathDef
//    {
//    public:
//        static slope CalculeSlope(VART::Point4D pos_01,VART::Point4D pos_02);
//        static double CalAngleDirection(VART::Point4D direction);
//
//        //TODO: [D] estes mÈtodos deveriam ser todos VPPoint2D?
//        /* VPPoint2D */ static double TriangleArea2D(const VART::Point4D &p0, const VART::Point4D &p1, const VART::Point4D &p2);
//        /* VPPoint2D */ static bool PointInTriangle2D(const VART::Point4D &p, const S3_P4D &tri);
//        /* VPPoint2D */ static VART::Point4D ptoParametric2D(VART::Point4D pto1, VART::Point4D pto2, double u);
//        /* VPPoint2D */ static double ptoParametric2D(VART::Point4D pto1, VART::Point4D pto2, VART::Point4D ptoI);
//        /* VPPoint2D */ static double distance2D(VART::Point4D p1, VART::Point4D p2);
//        /* VPPoint2D */ static double distance2D(VART::Point4D p);
//
//        //TODO: [D] deprecate, conferir.
//        //unsigned int cn_PnPoly(VART::Point4D P, VART::Point4D* V, unsigned int n);
//        static unsigned int intersect2D_SegPoly(Segment_Point4D S, VART::Point4D* V, const unsigned int n);
//        static int inSegment(VART::Point4D P, Segment_Point4D S);
//        static int intersect2D_Segments(Segment_Point4D S1, Segment_Point4D S2, VART::Point4D& I0);
//
//        //TODO: [D] deprecated: not used
//        //deprecated: static double acuteAngle(VART::Point4D ptoAngle, VART::Point4D p1, VART::Point4D p2);
//        //deprecated: static double acuteAngle(double co, double h);
//        //deprecated: static void normalPlane(VART::Point4D &v0, VART::Point4D &v1, VART::Point4D &v2, VART::Point4D &normal);
//        //deprecated: static double distance3D(VART::Point4D p);
//        //deprecated: /* VPPoint2D */ static double dotVector2D(VART::Point4D p1,VART::Point4D p2);
//        //deprecated: static double dotVector3D(VART::Point4D v1, VART::Point4D v2);
//        //deprecated: /* VPPoint2D */ static double angleVector2D(VART::Point4D p1,VART::Point4D p2,VART::Point4D p3,VART::Point4D p4);
//        //deprecated: static double angleVector3D(VART::Point4D p1,VART::Point4D p2,VART::Point4D p3,VART::Point4D p4);
//        //deprecated: /* VPPoint2D */ static VART::Point4D normalVector2D(VART::Point4D vec);
//        //deprecated: static VART::Point4D normalVector3D(VART::Point4D vec);
//        //deprecated: /* VPPoint2D */ static VART::Point4D subtractVector2D(VART::Point4D p1, VART::Point4D p2);
//        //deprecated: /* VPPoint2D */ static VART::Point4D multiplyVector2D(VART::Point4D p1, double v);
//        //deprecated: /* VPPoint2D */ static bool nearPoint2D(VART::Point4D posModel,VART::Point4D poskeyPoint,double &disTmp);
//        //deprecated: /* VPPoint2D */ static double lineAngle(VART::Point4D p1,VART::Point4D p2);
//    };
} // end namespace
#endif  // RAS_MATHDEF_H
