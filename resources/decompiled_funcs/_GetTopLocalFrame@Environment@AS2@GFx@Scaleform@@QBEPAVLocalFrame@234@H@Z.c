Scaleform::GFx::AS2::LocalFrame *__thiscall Scaleform::GFx::AS2::Environment::GetTopLocalFrame(
        Scaleform::GFx::AS2::Environment *this,
        int off)
{
  int v2; // eax

  v2 = this->LocalFrames.Data.Size - off;
  if ( v2 )
    return this->LocalFrames.Data.Data[v2 - 1].pObject;
  else
    return 0;
}
