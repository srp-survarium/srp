void __thiscall Scaleform::GFx::AS2::Value::operator=(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::ASStringNode *pStringNode; // esi
  Scaleform::GFx::ASStringNode *v4; // eax
  int v5; // eax
  int v6; // edx
  Scaleform::GFx::AS2::LocalFrame *v7; // edx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // ecx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // esi
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+Ch] [ebp-8h]
  char v19; // [esp+10h] [ebp-4h]

  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = v->T.Type;
  switch ( v->T.Type )
  {
    case 2u:
      this->V.BooleanValue = v->V.BooleanValue;
      break;
    case 3u:
      this->NV.NumberValue = v->NV.NumberValue;
      break;
    case 4u:
      this->NV.Int32Value = v->NV.Int32Value;
      break;
    case 5u:
    case 0xBu:
      pStringNode = v->V.pStringNode;
      this->NV.Int32Value = (int)pStringNode;
      ++pStringNode->RefCount;
      break;
    case 6u:
      v4 = v->V.pStringNode;
      if ( v4 )
      {
        if ( (*(int (__thiscall **)(unsigned int *))(v4->HashFlags + 8))(&v4->HashFlags) == 23 )
        {
          this->T.Type = 8;
          v5 = (*(int (__thiscall **)(int, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_DWORD *)(v->NV.Int32Value + 16)
                                                                                       + 48))(
                 v->NV.Int32Value + 16,
                 &v17);
          this->V.FunctionValue.Flags = 0;
          v6 = *(_DWORD *)v5;
          this->NV.Int32Value = *(_DWORD *)v5;
          if ( v6 )
            *(_DWORD *)(v6 + 12) = (*(_DWORD *)(v6 + 12) + 1) & 0x8FFFFFFF;
          this->V.FunctionValue.pLocalFrame = 0;
          v7 = *(Scaleform::GFx::AS2::LocalFrame **)(v5 + 4);
          if ( v7 )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, v7, *(_BYTE *)(v5 + 8) & 1);
          if ( (v19 & 2) == 0 )
          {
            if ( v17 )
            {
              RefCount = v17->RefCount;
              v9 = v17;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
              {
                v17->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
              }
            }
          }
          v17 = 0;
          if ( (v19 & 1) == 0 && v18 )
          {
            v10 = v18->RefCount;
            v11 = v18;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v10) != 0 )
            {
              v18->RefCount = v10 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
            }
          }
        }
        else
        {
          v12 = v->V.pStringNode;
          this->NV.Int32Value = (int)v12;
          v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
        }
      }
      else
      {
        this->NV.Int32Value = 0;
      }
      break;
    case 7u:
      v13 = v->V.pStringNode;
      this->NV.Int32Value = (int)v13;
      if ( v13 )
        ++v13->pData;
      break;
    case 8u:
    case 0xCu:
      this->V.FunctionValue.Flags = 0;
      v14 = v->V.pStringNode;
      this->NV.Int32Value = (int)v14;
      if ( v14 )
        v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
      this->V.FunctionValue.pLocalFrame = 0;
      pLocalFrame = v->V.FunctionValue.pLocalFrame;
      if ( pLocalFrame )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
          &this->V.FunctionValue,
          pLocalFrame,
          v->V.FunctionValue.Flags & 1);
      break;
    case 9u:
      v16 = v->V.pStringNode;
      this->NV.Int32Value = (int)v16;
      v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
      break;
    default:
      return;
  }
}
