void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::hitTestTextNearPos(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        long double *result,
        long double x,
        long double y,
        long double maxDistance)
{
  float v5; // [esp+4h] [ebp-8h]
  float closedist; // [esp+8h] [ebp-4h]
  float maxDistancea; // [esp+24h] [ebp+18h]
  float maxDistanceb; // [esp+24h] [ebp+18h]
  float maxDistancec; // [esp+24h] [ebp+18h]

  maxDistancea = maxDistance * 20.0;
  closedist = maxDistancea;
  maxDistanceb = y * 20.0;
  v5 = maxDistanceb;
  maxDistancec = 20.0 * x;
  *result = (double)Scaleform::GFx::StaticTextSnapshotData::HitTestTextNearPos(
                      &this->SnapshotData,
                      maxDistancec,
                      v5,
                      closedist);
}
