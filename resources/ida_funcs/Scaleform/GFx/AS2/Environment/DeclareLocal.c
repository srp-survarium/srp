void __thiscall Scaleform::GFx::AS2::Environment::DeclareLocal(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS2::Value val; // [esp+4h] [ebp-10h] BYREF

  Size = this->LocalFrames.Data.Size;
  if ( Size
    && this->LocalFrames.Data.Data[Size - 1].pObject
    && !Scaleform::GFx::AS2::Environment::FindLocal(this, varname) )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::AddLocal(this, varname, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
}
