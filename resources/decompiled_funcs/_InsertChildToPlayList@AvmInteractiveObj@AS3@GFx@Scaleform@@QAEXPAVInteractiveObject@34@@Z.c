void __thiscall Scaleform::GFx::AS3::AvmInteractiveObj::InsertChildToPlayList(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *v2; // eax

  v2 = this->FindInsertToPlayList(this, ch);
  if ( v2 )
    Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(ch, v2);
  else
    Scaleform::GFx::InteractiveObject::AddToPlayList(ch);
}
