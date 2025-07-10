void __cdecl Scaleform::Render::TessellateQuadCurve(
        Scaleform::Render::TessBase *con,
        const Scaleform::Render::ToleranceParams *param,
        float x2,
        float y2,
        float x3,
        float y3)
{
  float v7; // [esp+8h] [ebp-24h]
  float x1; // [esp+28h] [ebp-4h]
  float y1; // [esp+30h] [ebp+4h]
  float y1a; // [esp+30h] [ebp+4h]

  x1 = con->GetLastX(con);
  y1 = con->GetLastY(con);
  if ( !Scaleform::Render::TestQuadCollinearity(con, param, x1, y1, x2, y2, x3, y3) )
  {
    v7 = y1;
    y1a = param->CurveTolerance * 0.25 * (param->CurveTolerance * 0.25);
    Scaleform::Render::TessellateQuadRecursively(con, y1a, x1, v7, x2, y2, x3, y3, 0);
  }
}
