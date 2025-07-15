void __cdecl Scaleform::Render::TessellateCubicCurve(
        Scaleform::Render::TessBase *con,
        const Scaleform::Render::ToleranceParams *param,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4)
{
  float v9; // [esp+8h] [ebp-28h]
  float x1; // [esp+2Ch] [ebp-4h]
  float y1; // [esp+34h] [ebp+4h]
  float y1a; // [esp+34h] [ebp+4h]

  x1 = con->GetLastX(con);
  y1 = con->GetLastY(con);
  v9 = y1;
  y1a = param->CurveTolerance * 0.25 * (param->CurveTolerance * 0.25);
  Scaleform::Render::TessellateCubicRecursively(con, y1a, x1, v9, x2, y2, x3, y3, x4, y4, 0);
}
