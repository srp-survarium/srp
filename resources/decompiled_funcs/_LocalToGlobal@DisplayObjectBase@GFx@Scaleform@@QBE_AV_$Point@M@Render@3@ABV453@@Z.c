Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::DisplayObjectBase::LocalToGlobal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::Render::Point3<float> v4; // [esp+4h] [ebp-Ch] BYREF

  v4.x = ptIn->x;
  v4.y = ptIn->y;
  v4.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(this, result, &v4);
  return result;
}
