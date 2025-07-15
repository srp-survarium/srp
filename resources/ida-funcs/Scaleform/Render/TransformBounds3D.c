Scaleform::Render::Rect<float> *__cdecl Scaleform::Render::TransformBounds3D(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix4x4<float> *viewproj,
        const Scaleform::Render::Viewport *vp,
        const Scaleform::Render::Matrix3x4<float> *viewMatrix,
        __m128 *inputBounds,
        bool orient)
{
  unsigned int v6; // eax
  int Width; // eax
  int Height; // ecx
  Scaleform::Render::Rect<float> bounds; // [esp+Ch] [ebp-50h] BYREF
  Scaleform::Render::Matrix4x4<float> v11; // [esp+1Ch] [ebp-40h] BYREF

  bounds.x1 = 0.0;
  bounds.y1 = 0.0;
  bounds.x2 = 0.0;
  bounds.y2 = 0.0;
  Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v11, viewproj, viewMatrix);
  Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(&v11, (__m128 *)&bounds, inputBounds);
  v6 = vp->Flags & 0x30;
  if ( (v6 == 16 || v6 == 48) && orient )
  {
    Width = vp->Width;
    Height = vp->Height;
  }
  else
  {
    Width = vp->Height;
    Height = vp->Width;
  }
  Scaleform::Render::Viewport::ScaleToViewport<int>(result, 0, 0, Height, Width, &bounds);
  return result;
}
