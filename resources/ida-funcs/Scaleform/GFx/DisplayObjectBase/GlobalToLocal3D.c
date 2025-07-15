Scaleform::Render::Point3<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GlobalToLocal3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point3<float> *result,
        const Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::Render::Point3<float> *v3; // eax
  Scaleform::Render::Point<float> resulta; // [esp+0h] [ebp-8h] BYREF

  Scaleform::GFx::DisplayObjectBase::GlobalToLocal(this, &resulta, ptIn);
  v3 = result;
  result->x = resulta.x;
  result->y = resulta.y;
  result->z = 0.0;
  return v3;
}
