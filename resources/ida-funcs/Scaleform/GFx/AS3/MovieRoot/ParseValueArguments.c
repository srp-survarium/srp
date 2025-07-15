void __thiscall Scaleform::GFx::AS3::MovieRoot::ParseValueArguments(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *arr,
        const char *pmethodName,
        const char *pargFmt,
        char *args)
{
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // ebp
  char v6; // al
  __int16 Flags; // cx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // edx
  const char *v9; // edi
  char *v10; // esi
  char *v11; // ebx
  char v12; // al
  int v; // edx
  long double v14; // st7
  char v15; // al
  __m128i *v16; // eax
  Scaleform::GFx::ASString *String; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  char v19; // al
  wchar_t *v20; // eax
  const Scaleform::GFx::ASString *v21; // eax
  char i; // al
  Scaleform::GFx::LogState *pObject; // [esp+18h] [ebp-3Ch]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [esp+20h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::Value arg; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v29; // [esp+44h] [ebp-10h] BYREF

  pObject = Scaleform::GFx::StateBag::GetLogState(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  v5 = arr;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &arr->Data,
    arr,
    0);
  if ( pargFmt )
  {
    v6 = *pargFmt;
    Flags = 0;
    pWeakProxy = 0;
    v9 = pargFmt + 1;
    arg.Flags = 0;
    arg.Bonus.pWeakProxy = 0;
    if ( v6 )
    {
      v10 = args - 4;
      v11 = args - 8;
      while ( 1 )
      {
        if ( v6 != 37 )
        {
          if ( pObject )
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
              &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
              "ParseArguments('%s','%s') - invalid char '%c'",
              pmethodName,
              pargFmt,
              v6);
          goto LABEL_34;
        }
        v12 = *v9++;
        switch ( v12 )
        {
          case 'd':
            v = *((_DWORD *)v10 + 1);
            v10 += 4;
            v11 += 4;
            Scaleform::GFx::AS3::Value::SetSInt32(&arg, v);
            Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &v5->Data,
              &arg);
            break;
          case 'u':
            Scaleform::GFx::AS3::Value::SetUndefined(&arg);
            Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &v5->Data,
              &arg);
            break;
          case 'n':
            Scaleform::GFx::AS3::Value::SetNull(&arg);
            Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &v5->Data,
              &arg);
            break;
          case 'b':
            v10 += 4;
            v11 += 4;
            Scaleform::GFx::AS3::Value::SetBool(&arg, *(_DWORD *)v10 != 0);
            Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &v5->Data,
              &arg);
            break;
          default:
            switch ( v12 )
            {
              case 'f':
                goto LABEL_16;
              case 'h':
                v15 = *v9++;
                if ( v15 != 102 )
                {
                  if ( pObject )
                    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                      &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                      "ParseArguments('%s','%s') - invalid format '%%h%c'",
                      pmethodName,
                      pargFmt,
                      v15);
                  goto LABEL_34;
                }
LABEL_16:
                v14 = *((double *)v11 + 1);
                v11 += 8;
                v10 += 8;
                Scaleform::GFx::AS3::Value::SetNumber(&arg, v14);
                Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                  &v5->Data,
                  &arg);
                goto LABEL_34;
              case 's':
                v16 = (__m128i *)*((_DWORD *)v10 + 1);
                v10 += 4;
                v11 += 4;
                String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                           &this->BuiltinsMgr,
                           (Scaleform::GFx::ASString *)&arr,
                           v16);
                Scaleform::GFx::AS3::Value::Value(&val, String);
                Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                  &v5->Data,
                  &val);
                Scaleform::GFx::AS3::Value::~Value(&val);
                v18 = (Scaleform::GFx::ASStringNode *)arr;
                break;
              case 'l':
                v19 = *v9++;
                if ( v19 != 115 )
                {
                  if ( pObject )
                    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                      &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                      "ParseArguments('%s','%s') - invalid format '%%l%c'",
                      pmethodName,
                      pargFmt,
                      v19);
                  goto LABEL_34;
                }
                v20 = (wchar_t *)*((_DWORD *)v10 + 1);
                v10 += 4;
                v11 += 4;
                v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                        &this->BuiltinsMgr,
                        (Scaleform::GFx::ASString *)&args,
                        v20,
                        -1);
                Scaleform::GFx::AS3::Value::Value(&v29, v21);
                Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                  &v5->Data,
                  &v29);
                Scaleform::GFx::AS3::Value::~Value(&v29);
                v18 = (Scaleform::GFx::ASStringNode *)args;
                break;
              default:
                if ( pObject )
                  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                    &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                    "ParseArguments('%s','%s') - invalid format '%%%c'",
                    pmethodName,
                    pargFmt,
                    v12);
                goto LABEL_34;
            }
            if ( !--v18->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v18);
            break;
        }
LABEL_34:
        for ( i = *v9; i; i = *++v9 )
        {
          if ( i != 32 && i != 9 && i != 44 )
            break;
        }
        v6 = *v9++;
        if ( !v6 )
        {
          pWeakProxy = arg.Bonus.pWeakProxy;
          Flags = arg.Flags;
          break;
        }
      }
    }
    if ( (Flags & 0x1Fu) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&arg);
      }
    }
  }
}
