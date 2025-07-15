Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::Value::ToObject(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  unsigned __int8 Type; // cl
  Scaleform::GFx::AS2::Object *result; // eax
  Scaleform::GFx::AS2::Object *v5; // esi
  char v6; // bl
  int v7; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // ecx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // ecx
  int v12; // eax
  Scaleform::GFx::InteractiveObject *AvmTarget; // eax
  Scaleform::GFx::AS2::Object *v14; // esi
  Scaleform::GFx::AS2::Value v15; // [esp+Ch] [ebp-10h] BYREF

  Type = this->T.Type;
  switch ( Type )
  {
    case 6u:
      result = this->V.pObjectValue;
      break;
    case 8u:
      result = this->V.pObjectValue;
      if ( !result )
        goto LABEL_26;
      break;
    case 9u:
      if ( Type != 9 )
        goto LABEL_26;
      AvmTarget = Scaleform::GFx::AS2::Environment::GetAvmTarget(penv);
      if ( !AvmTarget )
        goto LABEL_26;
      v15.T.Type = 0;
      if ( !Scaleform::GFx::AS2::Value::GetPropertyValue(
              this,
              penv,
              (Scaleform::GFx::AS2::ObjectInterface *)&AvmTarget->RefCount,
              &v15) )
      {
        if ( v15.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v15);
        goto LABEL_26;
      }
      v14 = Scaleform::GFx::AS2::Value::ToObject(&v15, penv);
      if ( v15.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v15);
      result = v14;
      break;
    case 0xBu:
      Scaleform::GFx::AS2::Value::ResolveFunctionName(this, (Scaleform::GFx::AS2::FunctionRef *)&v15, penv);
      v5 = *(Scaleform::GFx::AS2::Object **)&v15.T.Type;
      if ( *(_DWORD *)&v15.T.Type )
      {
        v6 = BYTE4(v15.NV.NumberValue);
        if ( (BYTE4(v15.NV.NumberValue) & 2) == 0 )
        {
          v7 = *(_DWORD *)(*(_DWORD *)&v15.T.Type + 12);
          if ( (v7 & 0x3FFFFFF) != 0 )
          {
            v8 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v15.T.Type;
            *(_DWORD *)(*(_DWORD *)&v15.T.Type + 12) = v7 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
          }
        }
        if ( (v6 & 1) == 0 )
        {
          pStringNode = v15.V.pStringNode;
          if ( v15.NV.Int32Value )
          {
            v10 = *(_DWORD *)(v15.NV.Int32Value + 12);
            if ( (v10 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(v15.NV.Int32Value + 12) = v10 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
        result = v5;
      }
      else
      {
        if ( (BYTE4(v15.NV.NumberValue) & 1) != 0 )
          goto LABEL_26;
        v11 = v15.V.pStringNode;
        if ( !v15.NV.Int32Value )
          goto LABEL_26;
        v12 = *(_DWORD *)(v15.NV.Int32Value + 12);
        if ( (v12 & 0x3FFFFFF) == 0 )
          goto LABEL_26;
        *(_DWORD *)(v15.NV.Int32Value + 12) = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11);
        result = 0;
      }
      break;
    default:
LABEL_26:
      result = 0;
      break;
  }
  return result;
}
