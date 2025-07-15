void __userpurge Scaleform::GFx::AS2::AvmSwfEvent::AttachTo(
        Scaleform::GFx::AS2::AvmSwfEvent *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Scaleform::GFx::AS2::ActionBuffer *ch)
{
  Scaleform::GFx::AS2::ActionBufferData *pObject; // eax
  Scaleform::GFx::AS2::AvmCharacter *v6; // ecx
  Scaleform::GFx::AS2::Environment *v7; // ebp
  Scaleform::MemoryHeap *pHeap; // edi
  Scaleform::GFx::AS2::ActionBuffer *v9; // eax
  unsigned int Id; // eax
  unsigned int v11; // eax
  bool v12; // zf
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType v13; // esi
  Scaleform::GFx::AS2::AsFunctionObject *v14; // eax
  Scaleform::GFx::AS2::FunctionObject *v15; // eax
  Scaleform::GFx::AS2::FunctionObject *v16; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::AvmCharacter *v18; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS2::FunctionRef func; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value method; // [esp+20h] [ebp-10h] BYREF

  pObject = this->pActionOpData.pObject;
  if ( !pObject || !pObject->BufferLen || !*pObject->pBuffer )
    return;
  if ( ch )
  {
    v18 = (Scaleform::GFx::AS2::AvmCharacter *)((int (__thiscall *)(char *))(&ch->__vftable)[BYTE1(ch[2].__vftable)][1].~Scaleform::GFx::AS2::ActionBuffer)((char *)ch + 4 * BYTE1(ch[2].__vftable));
    v6 = v18;
  }
  else
  {
    v6 = 0;
    v18 = 0;
  }
  v7 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::AS2::AvmCharacter *, int, int))v6->GetASEnvironment)(
                                             v6,
                                             a2,
                                             a3);
  pHeap = v7->StringContext.pContext->pHeap;
  v9 = (Scaleform::GFx::AS2::ActionBuffer *)pHeap->Alloc(pHeap, 32u, 0);
  if ( v9 )
    Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
      v9,
      &v7->StringContext,
      (Scaleform::GFx::Resource *)this->pActionOpData.pObject);
  Id = this->Event.Id;
  if ( this->Event.Id > 0x200 )
  {
    v12 = Id == 0x40000;
  }
  else
  {
    if ( this->Event.Id == 512 )
      goto LABEL_15;
    v11 = Id - 1;
    if ( !v11 )
      goto LABEL_15;
    v12 = v11 == 3;
  }
  v13 = Exec_Event;
  if ( v12 )
LABEL_15:
    v13 = Exec_SpecialEvent;
  v14 = (Scaleform::GFx::AS2::AsFunctionObject *)pHeap->Alloc(pHeap, 108u, 0);
  if ( v14 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      v14,
      v7,
      ch,
      0,
      this->pActionOpData.pObject->BufferLen,
      0,
      v13);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  func.Flags = 0;
  func.Function = v16;
  func.pLocalFrame = 0;
  Scaleform::GFx::AS2::Value::Value(&method, &func);
  if ( v16 )
  {
    RefCount = v16->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v16->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
    }
  }
  Scaleform::GFx::AS2::AvmCharacter::SetClipEventHandlers(v18, &this->Event, &method);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( ch )
    Scaleform::RefCountNTSImpl::Release(ch);
}
