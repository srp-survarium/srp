void __thiscall Scaleform::GFx::AS2::Value::DropRefs(Scaleform::GFx::AS2::Value *this)
{
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  bool v3; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObjectValue; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // edi

  switch ( this->T.Type )
  {
    case 5u:
    case 0xBu:
      pStringNode = this->V.pStringNode;
      v3 = pStringNode->RefCount-- == 1;
      if ( v3 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pStringNode);
      break;
    case 6u:
    case 9u:
      v8 = this->V.pStringNode;
      if ( v8 )
      {
        Scaleform::GFx::AS2::RefCountBaseGC<323>::Release((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8);
        this->NV.Int32Value = 0;
      }
      break;
    case 7u:
      v9 = this->V.pStringNode;
      if ( v9 )
      {
        if ( (int)--v9->pData <= 0 )
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle((Scaleform::GFx::CharacterHandle *)v9);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
        }
        this->NV.Int32Value = 0;
      }
      break;
    case 8u:
    case 0xCu:
      if ( this->NV.Int32Value )
      {
        if ( (this->V.FunctionValue.Flags & 2) == 0 )
        {
          pObjectValue = this->V.pObjectValue;
          if ( pObjectValue )
          {
            RefCount = pObjectValue->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
            {
              pObjectValue->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObjectValue);
            }
          }
        }
        v3 = (this->V.FunctionValue.Flags & 1) == 0;
        this->NV.Int32Value = 0;
        if ( v3 )
        {
          pLocalFrame = this->V.FunctionValue.pLocalFrame;
          if ( pLocalFrame )
          {
            v7 = pLocalFrame->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v7) != 0 )
            {
              pLocalFrame->RefCount = v7 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
        this->V.FunctionValue.pLocalFrame = 0;
      }
      break;
    default:
      return;
  }
}
