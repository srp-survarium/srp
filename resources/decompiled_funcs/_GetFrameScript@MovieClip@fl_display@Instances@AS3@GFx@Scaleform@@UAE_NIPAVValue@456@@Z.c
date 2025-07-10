char __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetFrameScript(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        unsigned int frame,
        Scaleform::GFx::AS3::Value *pmethod)
{
  const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v3; // eax
  unsigned int v4; // ecx

  v3 = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Get(&this->mFrameScript, frame);
  if ( !v3 )
    return 0;
  v4 = v3->Method.Flags & 0x1F;
  if ( v4 <= 0xF && v4 != 14 && v4 != 5 && v4 != 15 && v4 != 6 && v4 != 7 && v4 != 12 && v4 != 13 )
    return 0;
  if ( v4 - 12 <= 3 && !v3->Method.value.VS._1.VInt )
    return 0;
  Scaleform::GFx::AS3::Value::Assign(pmethod, &v3->Method);
  return 1;
}
