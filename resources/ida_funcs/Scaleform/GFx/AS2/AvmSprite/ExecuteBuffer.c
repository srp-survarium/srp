char __thiscall Scaleform::GFx::AS2::AvmSprite::ExecuteBuffer(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ActionBuffer *pactionbuffer)
{
  Scaleform::GFx::AS2::Environment *v2; // eax

  if ( (this->pDispObj->Flags & 0x10) != 0 )
    return 0;
  v2 = this->GetASEnvironment(this);
  Scaleform::GFx::AS2::ActionBuffer::Execute(
    pactionbuffer,
    v2,
    0,
    pactionbuffer->pBufferData.pObject->BufferLen,
    0,
    0,
    Exec_Unknown);
  return 1;
}
