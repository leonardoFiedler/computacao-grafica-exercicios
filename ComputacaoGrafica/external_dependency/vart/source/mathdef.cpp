/// \file mathdef.cpp
/// \brief Implementation file for RAS class "MathDef".
/// \version $Revision: 0 $

#include "../mathdef.h"
//#include "msg.h"
#include <math.h>

//using namespace VART;

//TODO: rever todos os metodos a baixo.

//RAS::slope RAS::MathDef::CalculeSlope(Point4D pos_01,Point4D pos_02)
//{
//    slope sl;
//    sl.angle = 0.0;
//    sl.deltaX = (pos_02.GetX() - pos_01.GetX());
//    sl.deltaZ = (pos_02.GetZ() - pos_01.GetZ());
//    if (0 == sl.deltaX)
//    {
//        sl.angle = 90.0 * RAS_DEG_TO_RAD;
//    }
//    else if (0 == sl.deltaZ)
//    {
//        sl.angle = 0.0;
//    }
//    else
//    {
//        sl.angle = atan(sl.deltaZ / sl.deltaX);
//        if (pos_02.GetX() > pos_01.GetX())
//        {
//            if (pos_02.GetZ() > pos_01.GetZ())
//            {
//                //TODO: [D] este teste faz sentido 
//            }
//            else
//            {
//                sl.angle = 180.0 * RAS_DEG_TO_RAD + sl.angle;
//            }
//        }
//        else
//        {
//            if (pos_02.GetZ() > pos_01.GetZ())
//            {
//                //TODO: [D] este teste faz sentido 
//                //sl.angle = 90.0 * RAS_DEG_TO_RAD + sl.angle;
//            }
//            else
//            {
//                sl.angle = 180 * RAS_DEG_TO_RAD + sl.angle;
//            }
//        }
//    }
//    sl.scaleFactor = sqrt(sl.deltaX * sl.deltaX + sl.deltaZ * sl.deltaZ);
//    return sl;
//}

//double RAS::MathDef::CalAngleDirection(Point4D direction) 
//{
//    Point4D refVec(1,0,0);
//    //direction.Normalize();   //TODO: [D] parece desnecess·rio, tirei para otimizar.
//
//    double angle = refVec.AngleTo(direction) * RAS_RAD_TO_DEG;
//    if ((refVec.GetZ() * direction.GetX()) - (refVec.GetX() * direction.GetZ()) < 0.0)
//    {
//        angle = 360.0 - angle;
//    }
//    return angle;
//}

//double RAS::MathDef::TriangleArea2D(const Point4D &p0, const Point4D &p1, const Point4D &p2)
//{
//    double a = (p0.GetX() - p2.GetX());
//    double b = (p0.GetZ() - p2.GetZ());
//    double c = (p1.GetX() - p2.GetX());
//    double d = (p1.GetZ() - p2.GetZ());
//    return (0.5 * abs ((a*d) - (b*c)));
//}

//bool RAS::MathDef::PointInTriangle2D(const Point4D &p, const S3_P4D &tri)
//{
//    double area0 = TriangleArea2D(p, tri.p1, tri.p2);
//    double area1 = TriangleArea2D(p, tri.p0, tri.p2);
//    double area2 = TriangleArea2D(p, tri.p0, tri.p1);
//    double areaT = TriangleArea2D(tri.p0, tri.p1, tri.p2);
//
//    if ((area0 + area1 + area2) > (areaT + 0.000001 * areaT))
//        return false;
//    else
//        return true;
//}

//Point4D RAS::MathDef::ptoParametric2D(Point4D pto1, Point4D pto2, double u)
//{
//    return Point4D((pto1.GetX() + (pto2.GetX() - pto1.GetX()) * u),
//        (0.0),  
//        (pto1.GetZ() + (pto2.GetZ() - pto1.GetZ()) * u));
//}

//double RAS::MathDef::ptoParametric2D(Point4D pto1, Point4D pto2, Point4D ptoI)
//{
//    double x21 = pto2.GetX() - pto1.GetX();
//    if (x21 != 0)
//        return ((ptoI.GetX() - pto1.GetX()) / (x21));
//    double z21 = pto2.GetZ() - pto1.GetZ();
//    if (z21 != 0)
//        return ((ptoI.GetZ() - pto1.GetZ()) / (z21));
//
////    Msg::Message("ptoParametric","It was not possible to calculate!");
//    return -1;
//}

//double RAS::MathDef::distance2D(Point4D p1, Point4D p2)
//{
//    Point4D           v(p2.GetX() - p1.GetX(), 0.0, p2.GetZ() - p1.GetZ());
//    return(distance2D(v));
//}

//double RAS::MathDef::distance2D(Point4D p)
//{
//    return(sqrt(pow(p.GetX(),2)+0.0+pow(p.GetZ(),2)));
//}

//===================================================================
//#define SMALL_NUM  0.00000001 // anything that avoids division overflow
//#define dot(u,v)   ((u).GetX() * (v).GetX() + (u).GetY() * (v).GetY() + (u).GetZ() * (v).GetZ())  // dot product (3D) which allows vector operations in arguments
//#define perp(u,v)  ((u).GetX() * (v).GetY() - (u).GetY() * (v).GetX())  // perp product (2D)

//TODO: [D] criar um Segmento no VART, e usar VPPoint2D para as funcoes que so usam 2D, ex: 
//                 cn_PnPoly, intersect2D_SegPoly e inSegment

//// cn_PnPoly(): crossing number test for a point in a polygon
////      Input:   P = a point,
////               V[] = vertex points of a polygon V[n+1] with V[n]=V[0]
////      Return:  0 = outside, 1 = inside
//unsigned int RAS::MathDef::cn_PnPoly(Point4D P, Point4D* V, unsigned int n)
//{
//    unsigned int    cn = 0;    // the crossing number counter
//
//    // loop through all edges of the polygon
//    for (unsigned int i=0; i<n; i++) {    // edge from V[i] to V[i+1]
//       if (((V[i].GetY() <= P.GetY()) && (V[i+1].GetY() > P.GetY()))    // an upward crossing
//        || ((V[i].GetY() > P.GetY()) && (V[i+1].GetY() <= P.GetY()))) { // a downward crossing
//            // compute the actual edge-ray intersect x-coordinate
//            double vt = (double)(P.GetY() - V[i].GetY()) / (V[i+1].GetY() - V[i].GetY());
//            if (P.GetX() < V[i].GetX() + vt * (V[i+1].GetX() - V[i].GetX())) // P.GetX() < intersect
//                ++cn;   // a valid crossing of y=P.GetY() right of P.GetX()
//        }
//    }
//    return (cn&1);    // 0 if even (out), and 1 if odd (in)
//}

//    Input:  S = 2D segment to intersect with the convex polygon
//            n = number of 2D points in the polygon
//            V[] = array of n+1 vertex points with V[n]=V[0]
//      Note: The polygon MUST be convex and
//                have vertices oriented counterclockwise (ccw).
//            This code does not check for and verify these conditions.
//    Output: *IS = the intersection segment (when it exists)
//    Return: 0 /*FALSE*/ = no intersection
//            1 /*TRUE*/  = a valid intersection segment exists
// intersect2D_SegPoly(): Intersection of a Segment with a Convex Polygon or Polyhedron

//unsigned int RAS::MathDef::intersect2D_SegPoly(Segment_Point4D S, Point4D* V, const unsigned int n)
//{
//    //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//    S.P0.SetY(S.P0.GetZ());
//    S.P1.SetY(S.P1.GetZ());
//
//    //    Segment_Point4D           IS;         // the intersection segment (when it exists)
//
//    if (S.P0 == S.P1) {                                              // the segment S is a single point
//        //        IS = S;                                                      // same point if inside polygon
//        //        return cn_PnPoly(S.P0, V, n);
////        Msg::Message("intersect2D_SegPoly", "The segment is a single point, please use cn_PnPoly!");
//        return(false);
//    }
//    double  tE = 0;                                                 // the maximum entering segment parameter
//    double  tL = 1;                                                 // the minimum leaving segment parameter
//    double  t, N, D;                                                // intersect parameter t = N / D
//    Vector4D dS = S.P1 - S.P0;                                            // the segment direction vector
//    Vector4D e;                                                       // edge vector
//    for (unsigned int i=0; i < n; i++)                              // process polygon edge V[i]V[i+1]
//    {
//        e = V[i+1] - V[i];
//        N = perp(e, S.P0-V[i]);
//        D = -perp(e, dS);
//        if (fabs(D) < SMALL_NUM) {                  // S is nearly parallel to this edge
//            if (N < 0)                              // S.P0 is outside this edge, so
//                return 0 /*FALSE*/;                 // S is outside the polygon
//            else                                    // S cannot cross this edge, so
//                continue;                           // ignore this edge
//        }
//        t = N / D;
//        if (D < 0) {                                // segment S is entering across this edge
//            if (t > tE) {                           // new max tE
//                tE = t;
//                if (tE > tL)                        // S enters after leaving polygon
//                    return 0 /*FALSE*/;
//            }
//        }
//        else {                                      // segment S is leaving across this edge
//            if (t < tL) {                           // new min tL
//                tL = t;
//                if (tL < tE)                        // S leaves before entering polygon
//                    return 0 /*FALSE*/;
//            }
//        }
//    }
//
//    // tE <= tL implies that there is a valid intersection subsegment
//    // = P(tE) = point where S enters polygon
//    //    IS.P0.GetX() = S.P0.GetX() + tE * dS.GetX();   IS.P0.GetY() = S.P0.GetY() + tE * dS.GetY();   IS.P0.GetZ() = S.P0.GetZ() + tE * dS.GetZ();
//    // = P(tL) = point where S leaves polygon
//    //    IS.P1.GetX() = S.P0.GetX() + tL * dS.GetX();   IS.P1.GetY() = S.P0.GetY() + tL * dS.GetY();   IS.P1.GetZ() = S.P0.GetZ() + tL * dS.GetZ();
//    return 1 /*TRUE*/;
//}

////===================================================================
//// inSegment(): determine if a point is inside a segment
////    Input:  a point P, and a collinear segment S
////    Return: 1 = P is inside S
////            0 = P is not inside S
//int RAS::MathDef::inSegment(Point4D P, Segment_Point4D S)
//{
//    //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//    P.SetY(P.GetZ());  S.P0.SetY(S.P0.GetZ());  S.P1.SetY(S.P1.GetZ());
//    if (S.P0.GetX() != S.P1.GetX()) {    // S is not vertical
//        if (S.P0.GetX() <= P.GetX() && P.GetX() <= S.P1.GetX())
//            return 1;
//        if (S.P0.GetX() >= P.GetX() && P.GetX() >= S.P1.GetX())
//            return 1;
//    }
//    else {    // S is vertical, so test y coordinate
//        if (S.P0.GetY() <= P.GetY() && P.GetY() <= S.P1.GetY())
//            return 1;
//        if (S.P0.GetY() >= P.GetY() && P.GetY() >= S.P1.GetY())
//            return 1;
//    }
//    return 0;
//}

//// intersect2D_2Segments(): the intersection of 2 finite 2D segments
////    Input:  two finite segments S1 and S2
////    Output: *I0 = intersect point (when it exists)
////            *I1 = endpoint of intersect segment [I0,I1] (when it exists)
////    Return: 0=disjoint (no intersect)
////            1=intersect in unique point I0
////            2=overlap in segment from I0 to I1
//int RAS::MathDef::intersect2D_Segments(Segment_Point4D S1, Segment_Point4D S2, Point4D& I0)
//{
//    //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//    S1.P0.SetY(S1.P0.GetZ());      S1.P1.SetY(S1.P1.GetZ());
//    S2.P0.SetY(S2.P0.GetZ());      S2.P1.SetY(S2.P1.GetZ());
//    Point4D       I1;
//    Vector4D    u = S1.P1 - S1.P0;
//    Vector4D    v = S2.P1 - S2.P0;
//    Vector4D    w = S1.P0 - S2.P0;
//    double     D = perp(u,v);
//    // test if they are parallel (includes either being a point)
//    if (fabs(D) < SMALL_NUM) {          // S1 and S2 are parallel
//        if (perp(u,w) != 0 || perp(v,w) != 0) {
//            return 0;                   // they are NOT collinear
//        }
//        // they are collinear or degenerate
//        // check if they are degenerate points
//        double du = dot(u,u);
//        double dv = dot(v,v);
//        if (du==0 && dv==0) {           // both segments are points
//            if (S1.P0 != S2.P0)         // they are distinct points
//                return 0;
//            I0 = S1.P0;                // they are the same point
//            //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//            I0.SetZ(I0.GetY());
//            return 1;
//        }
//        if (du==0) {                    // S1 is a single point
//            if (inSegment(S1.P0, S2) == 0)  // but is not in S2
//                return 0;
//            I0 = S1.P0;
//            //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//            I0.SetZ(I0.GetY());
//            return 1;
//        }
//        if (dv==0) {                    // S2 a single point
//            if (inSegment(S2.P0, S1) == 0)  // but is not in S1
//                return 0;
//            I0 = S2.P0;
//            //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//            I0.SetZ(I0.GetY());
//            return 1;
//        }
//        // they are collinear segments - get overlap (or not)
//        double t0, t1;                   // endpoints of S1 in eqn for S2
//        Vector4D w2 = S1.P1 - S2.P0;
//        if (v.GetX() != 0) {
//            t0 = w.GetX() / v.GetX();
//            t1 = w2.GetX() / v.GetX();
//        }
//        else {
//            t0 = w.GetY() / v.GetY();
//            t1 = w2.GetY() / v.GetY();
//        }
//        if (t0 > t1) {                  // must have t0 smaller than t1
//            double t=t0; t0=t1; t1=t;    // swap if not
//        }
//        if (t0 > 1 || t1 < 0) {
//            return 0;     // NO overlap
//        }
//        t0 = t0<0? 0 : t0;              // clip to min 0
//        t1 = t1>1? 1 : t1;              // clip to max 1
//        if (t0 == t1) {                 // intersect is a point
//            I0.SetX(S2.P0.GetX() + t0 * v.GetX());  I0.SetY(S2.P0.GetY() + t0 * v.GetY());  I0.SetZ(S2.P0.GetZ() + t0 * v.GetZ());
//            //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//            I0.SetZ(I0.GetY());
//            return 1;
//        }
//
//        // they overlap in a valid subsegment
//        I0.SetX(S2.P0.GetX() + t0 * v.GetX());  I0.SetY(S2.P0.GetY() + t0 * v.GetY());  I0.SetZ(S2.P0.GetZ() + t0 * v.GetZ());
//        I1.SetX(S2.P0.GetX() + t1 * v.GetX());  I1.SetY(S2.P0.GetY() + t1 * v.GetY());  I1.SetZ(S2.P0.GetZ() + t1 * v.GetZ());
//        //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//        I0.SetZ(I0.GetY());
//        I1.SetZ(I1.GetY());
//        return 2;
//    }
//    // the segments are skew and may intersect in a point
//    // get the intersect parameter for S1
//    double     sI = perp(v,w) / D;
//    if (sI < 0 || sI > 1)               // no intersect with S1
//        return 0;
//    // get the intersect parameter for S2
//    double     tI = perp(u,w) / D;
//    if (tI < 0 || tI > 1)               // no intersect with S2
//        return 0;
//    // compute S1 intersect point
//    I0.SetX(S1.P0.GetX() + sI * u.GetX());  I0.SetY(S1.P0.GetY() + sI * u.GetY());  I0.SetZ(S1.P0.GetZ() + sI * u.GetZ());
//    //TODO: passar ja um pto 2D... e tranformar a funcao em 2D
//    I0.SetZ(I0.GetY());
//    return 1;
//}

// deprecated: not used _____________________________________________________
//double RAS::MathDef::acuteAngle(Point4D ptoAngle, Point4D p1, Point4D p2)
//{
//    Point4D   ptoRightAngle = ptoParametric2D(p1, p2, 0.5);
//    double h  = distance2D(ptoAngle,p1);
//    double co = distance2D(ptoRightAngle,p1);
//
//    return acuteAngle(co, h);
//}
//
//double RAS::MathDef::acuteAngle(double co, double h)
//{
//    return RAS_RAD_TO_DEG * (asin(co / h));
//}
//
//void RAS::MathDef::normalPlane(Point4D &v0, Point4D &v1, Point4D &v2, Point4D &normal)
//{
//	normal.SetX(((v1.GetY() - v0.GetY()) * (v2.GetZ() - v0.GetZ())) - ((v1.GetZ() - v0.GetZ()) * (v2.GetY() - v0.GetY())));
//    normal.SetY(((v1.GetZ() - v0.GetZ()) * (v2.GetX() - v0.GetX())) - ((v1.GetX() - v0.GetX()) * (v2.GetZ() - v0.GetZ())));
//    normal.SetZ(((v1.GetX() - v0.GetX()) * (v2.GetY() - v0.GetY())) - ((v1.GetY() - v0.GetY()) * (v2.GetX() - v0.GetX())));
//
//	double lenght = sqrt(pow(normal.GetX(),2) + pow(normal.GetY(),2) + pow(normal.GetZ(),2));
//
//	normal.SetX(normal.GetX() / lenght);
//	normal.SetY(normal.GetY() / lenght);
//	normal.SetZ(normal.GetZ() / lenght);
//}
//
//double RAS::MathDef::distance3D(Point4D p)
//{
//   return(sqrt(pow(p.GetX(),2)+pow(p.GetY(),2)+pow(p.GetZ(),2)));
//}
//
//double RAS::MathDef::dotVector2D(Point4D p1,Point4D p2)
//{
//    return((p1.GetX() * p2.GetX()) + (p1.GetY() * p2.GetY()));
//}
//
////Acute Angle --> angle > 0
//double RAS::MathDef::dotVector3D(Point4D v1, Point4D v2)
//{
//    return v1.GetX() * v2.GetX() + v1.GetY() * v2.GetY() + v1.GetZ() * v2.GetZ();
//}
//
//double RAS::MathDef::angleVector2D(Point4D p1,Point4D p2,Point4D p3,Point4D p4)
//{
//    Point4D           v1(p2.GetX() - p1.GetX(), p2.GetY() - p1.GetY(), 0.0);      /* VPPoint2D */
//    Point4D           v2(p4.GetX() - p3.GetX(), p4.GetY() - p3.GetY(), 0.0);      /* VPPoint2D */
//    
//    return(acos((dotVector2D(v1,v2)) / (distance2D(v1) * distance2D(v2))) * RAS_RAD_TO_DEG);
//}
//
//double RAS::MathDef::angleVector3D(Point4D p1,Point4D p2,Point4D p3,Point4D p4)
//{
//    Point4D           v1(p2-p1);
//    Point4D           v2(p4-p3);
//    
//    return(acos((dotVector3D(v1,v2)) / (distance3D(v1) * distance3D(v2))) * RAS_RAD_TO_DEG);
//}
//
//Point4D RAS::MathDef::normalVector2D(Point4D vec)
//{
//    double lenght = sqrt(pow(vec.GetX(),2) + pow(vec.GetY(),2));
//   
//    if (lenght != 0)    {  vec.SetX(vec.GetX() / lenght); vec.SetY(vec.GetY() / lenght); }
//    else                {  vec.SetX(0);                    vec.SetY(0);       }
//    return vec;
//}
//
//Point4D RAS::MathDef::normalVector3D(Point4D vec)
//{
//    double lenght = sqrt(pow(vec.GetX(),2) + pow(vec.GetY(),2) + pow(vec.GetZ(),2));
//   
//    if (lenght != 0)    {  vec.SetX(vec.GetX() / lenght); vec.SetY(vec.GetY() / lenght); vec.SetZ(vec.GetZ() / lenght); }
//    else                {  vec.SetX(0);                    vec.SetY(0);       vec.SetZ(0);       }
//    return vec;
//}
//
//Point4D RAS::MathDef::subtractVector2D(Point4D p1, Point4D p2)
//{
//    return(Point4D(p2.GetX()-p1.GetX(),p2.GetY()-p1.GetY(), 0.0));        /* VPPoint2D */
//}
//
//Point4D RAS::MathDef::multiplyVector2D(Point4D p1, double v)
//{
//    return(Point4D(p1.GetX()*v,p1.GetY()-v, 0.0));              /* VPPoint2D */
//}
//
//bool RAS::MathDef::nearPoint2D(Point4D posModel,Point4D poskeyPoint,double &disTmp)
//{
//    double   disNew;
//    
//    disNew = distance2D(posModel,poskeyPoint);
//    if (disTmp < disNew)
//        return(false);
//    disTmp = disNew;
//    return(true);
//}
//
//double RAS::MathDef::lineAngle(Point4D p1,Point4D p2)
//{
//	double x0 = p1.GetX();        double y0 = p1.GetY();
//	double x1 = p2.GetX();        double y1 = p2.GetY();
//	double angle = 0;    
//	double distx = x1 - x0;  double disty = y1 - y0;
//
//	if (0.0 == distx)
//	{
//		if (y1 > y0)
//			angle = 90.0 * RAS_DEG_TO_RAD;
//		else
//			angle = 270.0 * RAS_DEG_TO_RAD;
//	}
//	else
//	{
//		if (0.0 == disty)
//		{
//			if (x1 > x0)
//				angle = 0.0;
//			else
//				angle = 180.0 * RAS_DEG_TO_RAD;
//		}
//		else
//		{
//			angle = atan(disty / distx);
//			if (y1 > y0)
//			{
//				if (x1 > x0)
//					angle = (360.0 * RAS_DEG_TO_RAD) - angle;
//				else
//					angle = (180.0 * RAS_DEG_TO_RAD) + angle;
//			}
//			else
//			{
//				if (x1 < x0)
//					angle = (90.0 * RAS_DEG_TO_RAD) + angle;
//				else
//					angle = -angle;
//			}
//		}
//	}
//	return angle * RAS_RAD_TO_DEG;
//}
