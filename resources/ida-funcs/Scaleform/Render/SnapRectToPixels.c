void __cdecl Scaleform::Render::SnapRectToPixels(Scaleform::Render::Rect<float> *rect)
{
  float v2; // [esp+10h] [ebp+4h]
  float v3; // [esp+10h] [ebp+4h]
  float v4; // [esp+10h] [ebp+4h]
  float v5; // [esp+10h] [ebp+4h]
  float v6; // [esp+10h] [ebp+4h]
  float v7; // [esp+10h] [ebp+4h]
  float v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+10h] [ebp+4h]

  v2 = rect->x1 - 10.0;
  v3 = floor(v2);
  rect->x1 = v3;
  v4 = rect->y1 - 10.0;
  v5 = floor(v4);
  rect->y1 = v5;
  v6 = rect->x2 + 10.0;
  v7 = ceil(v6);
  rect->x2 = v7;
  v8 = rect->y2 + 10.0;
  v9 = ceil(v8);
  rect->y2 = v9;
}
