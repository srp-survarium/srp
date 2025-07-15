void __cdecl Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // esi
  const char *pData; // eax
  Scaleform::GFx::ASStringNode *pLower; // edx
  int v4; // edi
  int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ebx
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Environment *Env; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // edi
  unsigned __int8 Type; // al
  Scaleform::GFx::ASStringNode **v14; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // ecx
  Scaleform::GFx::ASStringNode *v17; // ecx
  bool v18; // zf
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::Object *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v22; // ebx
  _DWORD *v23; // edx
  unsigned int v24; // eax
  Scaleform::GFx::AS2::Value *v25; // ecx
  unsigned __int8 v26; // cl
  char v27; // al
  Scaleform::GFx::ASStringNode **v28; // eax
  unsigned int v29; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // ecx
  Scaleform::GFx::ASStringNode *v31; // ecx
  Scaleform::GFx::AS2::Value *v32; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v33; // ebp
  char v34; // al
  int p_StringContext; // edi
  void (__thiscall *v36)(Scaleform::GFx::ASStringNode *, int, Scaleform::GFx::AS2::Value *, int, _DWORD); // edx
  unsigned int v37; // ecx
  char *v38; // eax
  Scaleform::GFx::AS2::Value *v39; // ecx
  unsigned __int8 (__thiscall *v40)(Scaleform::GFx::ASStringNode *, int, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *); // edx
  Scaleform::GFx::ASStringNode *v41; // eax
  unsigned int v42; // eax
  Scaleform::GFx::AS2::Environment *v43; // [esp+0h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v44; // [esp+0h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v45; // [esp+4h] [ebp-38h]
  char v46; // [esp+17h] [ebp-25h]
  Scaleform::GFx::ASStringNode *v47; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::ASStringNode *v48; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v49; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v50; // [esp+24h] [ebp-18h] BYREF
  int i; // [esp+28h] [ebp-14h]
  Scaleform::GFx::AS2::Value v52; // [esp+2Ch] [ebp-10h] BYREF

  v1 = (Scaleform::GFx::AS2::FnCall *)fn;
  pData = fn[1].pData;
  pLower = fn[1].pLower;
  v4 = (*((_DWORD *)pData + 1) - *((_DWORD *)pData + 2)) >> 4;
  v5 = 32 * (*((_DWORD *)pData + 6) - 1);
  i = *((unsigned __int8 *)pData + 120);
  v6 = 0;
  if ( (unsigned int)pLower <= v5 + v4 )
    v6 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(*((_DWORD *)pData + 5) + 4 * ((unsigned int)pLower >> 5))
                                      + 16 * ((unsigned __int8)pLower & 0x1F));
  v45 = (Scaleform::GFx::AS2::Environment *)fn[1].pData;
  if ( v6->T.Type == 7 )
  {
    v7 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v6, v45);
    if ( !v7 )
      return;
    v8 = (Scaleform::GFx::ASStringNode *)&v7->Scaleform::GFx::AS2::ObjectInterface;
    fn = (Scaleform::GFx::ASStringNode *)&v7->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v9 = Scaleform::GFx::AS2::Value::ToObject(v6, v45);
    if ( !v9 )
      return;
    fn = (Scaleform::GFx::ASStringNode *)&v9->Scaleform::GFx::AS2::ObjectInterface;
    v8 = (Scaleform::GFx::ASStringNode *)&v9->Scaleform::GFx::AS2::ObjectInterface;
  }
  if ( v8 )
  {
    Env = v1->Env;
    v11 = v1->FirstArgBottomIndex - 1;
    v12 = 0;
    if ( v11 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v12 = &Env->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
    Type = v12->T.Type;
    v47 = 0;
    switch ( Type )
    {
      case 5u:
        Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
        v14 = (Scaleform::GFx::ASStringNode **)Scaleform::GFx::AS2::StringProto::StringSplit(
                                                 (Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *)&v49,
                                                 v1->Env,
                                                 (const Scaleform::GFx::ASString *)&fn,
                                                 ",",
                                                 (Scaleform::String)0x3FFFFFFF);
        if ( *v14 )
          (*v14)->RefCount = ((*v14)->RefCount + 1) & 0x8FFFFFFF;
        v47 = *v14;
        if ( v49 )
        {
          RefCount = v49->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v16 = v49;
            v49->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
          }
        }
        v17 = fn;
        v18 = fn->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        break;
      case 6u:
        v43 = Env;
        v19 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        v20 = Scaleform::GFx::AS2::Value::ToObject(v19, v43);
        v21 = (Scaleform::GFx::ASStringNode *)v20;
        if ( v20 )
        {
          v22 = &v20->Scaleform::GFx::AS2::ObjectInterface;
          if ( v20->GetObjectType(&v20->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
          {
            v21->RefCount = (v21->RefCount + 1) & 0x8FFFFFFF;
            v47 = v21;
          }
          else
          {
            if ( v22->GetObjectType((Scaleform::GFx::AS2::ObjectInterface *)&v21->HashFlags) != Object_String )
              return;
            Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&v48, v1->Env, -1, 0);
            v28 = (Scaleform::GFx::ASStringNode **)Scaleform::GFx::AS2::StringProto::StringSplit(
                                                     (Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *)&v50,
                                                     v1->Env,
                                                     (const Scaleform::GFx::ASString *)&v48,
                                                     ",",
                                                     (Scaleform::String)0x3FFFFFFF);
            if ( *v28 )
              (*v28)->RefCount = ((*v28)->RefCount + 1) & 0x8FFFFFFF;
            v47 = *v28;
            if ( v50 )
            {
              v29 = v50->RefCount;
              if ( (v29 & 0x3FFFFFF) != 0 )
              {
                v30 = v50;
                v50->RefCount = v29 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
              }
            }
            v31 = v48;
            v18 = v48->RefCount-- == 1;
            if ( v18 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
          }
          v8 = fn;
        }
        break;
      case 1u:
        break;
      default:
        return;
    }
    v23 = &v1->Env->__vftable;
    v24 = v1->FirstArgBottomIndex - 2;
    v25 = 0;
    if ( v24 <= 32 * (v23[6] - 1) + ((v23[1] - v23[2]) >> 4) )
      v25 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v23[5] + 4 * (v24 >> 5)) + 16 * (v24 & 0x1F));
    v26 = Scaleform::GFx::AS2::Value::ToInt32(v25, v1->Env) & 7;
    v18 = v1->NArgs == 3;
    LOBYTE(fn) = v26;
    if ( v18 )
    {
      v27 = (i != 5) - 1;
    }
    else
    {
      v44 = v1->Env;
      v32 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
      v27 = Scaleform::GFx::AS2::Value::ToUInt32(v32, v44);
      v26 = (unsigned __int8)fn;
    }
    v33 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v47;
    v34 = v27 & 7;
    p_StringContext = (int)&v1->Env->StringContext;
    v46 = v34;
    if ( v47 )
    {
      v37 = v47[2].RefCount;
      v38 = 0;
      v48 = 0;
      for ( i = v37; (int)v48 < i; v48 = (Scaleform::GFx::ASStringNode *)((char *)v48 + 1) )
      {
        v39 = *(Scaleform::GFx::AS2::Value **)(v33[3].RootIndex + 4 * (_DWORD)v38);
        if ( v39 )
        {
          Scaleform::GFx::AS2::Value::ToStringImpl(v39, (Scaleform::GFx::ASString *)&v47, v1->Env, -1, 0);
          v40 = (unsigned __int8 (__thiscall *)(Scaleform::GFx::ASStringNode *, int, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))*((_DWORD *)v8->pData + 5);
          v52.T = 0;
          if ( v40(v8, p_StringContext, &v47, &v52) )
            (*((void (__thiscall **)(Scaleform::GFx::ASStringNode *, int, Scaleform::GFx::ASStringNode **, int))v8->pData
             + 7))(
              v8,
              p_StringContext,
              &v47,
              (unsigned __int8)fn | (unsigned __int8)(v52.T.PropFlags & ~v46));
          if ( v52.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v52);
          v41 = v47;
          --v47->RefCount;
          if ( !v41->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v41);
        }
        v38 = (char *)&v48->pData + 1;
      }
      v42 = v33->RefCount;
      if ( (v42 & 0x3FFFFFF) != 0 )
      {
        v33->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v33);
      }
    }
    else
    {
      v52.V.FunctionValue.Flags = v26;
      *((_BYTE *)&v52.NV + 13) = v34;
      v36 = (void (__thiscall *)(Scaleform::GFx::ASStringNode *, int, Scaleform::GFx::AS2::Value *, int, _DWORD))*((_DWORD *)v8->pData + 8);
      *(_DWORD *)&v52.T.Type = &`Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags'::`27'::MemberVisitor::`vftable';
      *(_QWORD *)&v52.NV.NumberValue = __PAIR64__(p_StringContext, (unsigned int)v8);
      v36(v8, p_StringContext, &v52, 12, 0);
    }
  }
}
