void __thiscall Scaleform::GFx::AS2::Value::Value(
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
  $998A3DB55198A9E0059CCBE6644E229E *v14; // ecx
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::ASStringNode *v17; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // [esp+Ch] [ebp-8h]
  char v20; // [esp+10h] [ebp-4h]

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
                 &v18);
          this->V.FunctionValue.Flags = 0;
          v6 = *(_DWORD *)v5;
          this->NV.Int32Value = *(_DWORD *)v5;
          if ( v6 )
            *(_DWORD *)(v6 + 12) = (*(_DWORD *)(v6 + 12) + 1) & 0x8FFFFFFF;
          this->V.FunctionValue.pLocalFrame = 0;
          v7 = *(Scaleform::GFx::AS2::LocalFrame **)(v5 + 4);
          if ( v7 )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, v7, *(_BYTE *)(v5 + 8) & 1);
          if ( (v20 & 2) == 0 )
          {
            if ( v18 )
            {
              RefCount = v18->RefCount;
              v9 = v18;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                v18->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
              }
            }
          }
          v18 = 0;
          if ( (v20 & 1) == 0 && v19 )
          {
            v10 = v19->RefCount;
            v11 = v19;
            if ( (v10 & 0x3FFFFFF) != 0 )
            {
              v19->RefCount = v10 - 1;
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
      v14 = &this->V.4;
      this->V.FunctionValue.Flags = 0;
      v15 = v->V.pStringNode;
      this->NV.Int32Value = (int)v15;
      if ( v15 )
        v15->RefCount = (v15->RefCount + 1) & 0x8FFFFFFF;
      this->V.FunctionValue.pLocalFrame = 0;
      pLocalFrame = v->V.FunctionValue.pLocalFrame;
      if ( pLocalFrame )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
          (Scaleform::GFx::AS2::FunctionRefBase *)v14,
          pLocalFrame,
          v->V.FunctionValue.Flags & 1);
      break;
    case 9u:
      v17 = v->V.pStringNode;
      this->NV.Int32Value = (int)v17;
      v17->RefCount = (v17->RefCount + 1) & 0x8FFFFFFF;
      break;
    default:
      return;
  }
}


void __thiscall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::FunctionRef *func)
{
  $998A3DB55198A9E0059CCBE6644E229E *v2; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  this->T.Type = 8;
  v2 = &this->V.4;
  v2->FunctionValue.Flags = 0;
  Function = func->Function;
  v2->pStringNode = (Scaleform::GFx::ASStringNode *)func->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  v2->FunctionValue.pLocalFrame = 0;
  pLocalFrame = func->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)v2,
      pLocalFrame,
      func->Flags & 1);
}


void __thiscall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        void (__cdecl *func)(const Scaleform::GFx::AS2::FnCall *))
{
  Scaleform::GFx::AS2::Object *v4; // eax
  int v5; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax

  this->T.Type = 8;
  v4 = (Scaleform::GFx::AS2::Object *)psc->pContext->pHeap->Alloc(psc->pContext->pHeap, 56, 0);
  v5 = (int)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, psc);
    *(_DWORD *)v5 = &Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v5 + 16) = &Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v5 + 52) = func;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
    Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)(v5 + 16), psc, Prototype);
  }
  else
  {
    v5 = 0;
  }
  this->NV.Int32Value = v5;
  this->V.FunctionValue.Flags = 0;
  this->V.FunctionValue.pLocalFrame = 0;
}


void __thiscall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax

  this->T.Type = 7;
  if ( pcharacter )
  {
    pObject = pcharacter->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pcharacter);
    this->NV.Int32Value = (int)pObject;
    if ( pObject )
      ++pObject->RefCount;
  }
  else
  {
    this->NV.Int32Value = 0;
  }
}


void __thiscall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // eax
  int Function; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  unsigned int v8; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // [esp+10h] [ebp-8h]
  char v12; // [esp+14h] [ebp-4h]

  if ( pobj && pobj->GetObjectType(&pobj->Scaleform::GFx::AS2::ObjectInterface) == Object_Function )
  {
    this->T.Type = 8;
    v3 = pobj->ToFunction(&pobj->Scaleform::GFx::AS2::ObjectInterface, &v10);
    this->V.FunctionValue.Flags = 0;
    Function = (int)v3->Function;
    this->NV.Int32Value = (int)v3->Function;
    if ( Function )
      *(_DWORD *)(Function + 12) = (*(_DWORD *)(Function + 12) + 1) & 0x8FFFFFFF;
    this->V.FunctionValue.pLocalFrame = 0;
    pLocalFrame = v3->pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, pLocalFrame, v3->Flags & 1);
    if ( (v12 & 2) == 0 )
    {
      if ( v10 )
      {
        RefCount = v10->RefCount;
        v7 = v10;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
    }
    v10 = 0;
    if ( (v12 & 1) == 0 && v11 )
    {
      v8 = v11->RefCount;
      v9 = v11;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  else
  {
    this->T.Type = 6;
    this->NV.Int32Value = (int)pobj;
    if ( pobj )
      pobj->RefCount = (pobj->RefCount + 1) & 0x8FFFFFFF;
  }
}


void __thiscall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this)
{
  this->T.Type = 0;
}
