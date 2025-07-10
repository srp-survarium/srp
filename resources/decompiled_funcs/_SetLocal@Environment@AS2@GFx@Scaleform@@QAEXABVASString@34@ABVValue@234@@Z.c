void __thiscall Scaleform::GFx::AS2::Environment::SetLocal(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname,
        const Scaleform::GFx::AS2::Value *val)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS2::Value *Local; // eax

  Size = this->LocalFrames.Data.Size;
  if ( Size && this->LocalFrames.Data.Data[Size - 1].pObject )
  {
    Local = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Environment::FindLocal(this, varname);
    if ( Local )
      Scaleform::GFx::AS2::Value::operator=(Local, val);
    else
      Scaleform::GFx::AS2::Environment::AddLocal(this, varname, val);
  }
}
