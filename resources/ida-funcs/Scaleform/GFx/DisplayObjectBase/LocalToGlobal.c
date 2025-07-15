Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::DisplayObjectBase::LocalToGlobal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::Render::Point3<float> ptIna; // [esp+4h] [ebp-Ch] BYREF

  ptIna.x = ptIn->x;
  ptIna.y = ptIn->y;
  ptIna.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(this, result, &ptIna);
  return result;
}
