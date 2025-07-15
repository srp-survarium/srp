int __thiscall Scaleform::GFx::AS3::Value::HashFunctor::operator()(
        Scaleform::GFx::AS3::Value::HashFunctor *this,
        const Scaleform::GFx::AS3::Object *v)
{
  unsigned int v2; // esi
  int v3; // ecx
  int result; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  Scaleform::GFx::AS3::Value::V1U pNext; // eax
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // edx
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // edi
  int v33; // ecx
  int v34; // eax
  int v35; // edi
  char v36; // [esp+3h] [ebp-9h]
  long double cv; // [esp+4h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v2 = (int)v->__vftable & 0x1F;
  v3 = 0;
  switch ( v2 )
  {
    case 1u:
      result = (LOBYTE(v->pNext) != 0) + v2;
      break;
    case 2u:
    case 3u:
      v5 = 5381;
      v6 = 4;
      do
      {
        v7 = *((unsigned __int8 *)&retaddr + v6-- + 3);
        v5 = v7 + 65599 * v5;
      }
      while ( v6 );
      result = v5 + v2;
      break;
    case 4u:
      v8 = 5381;
      cv = *(double *)&v->pNext;
      v9 = 8;
      do
      {
        v10 = (unsigned __int8)*(&v36 + v9--);
        v8 = v10 + 65599 * v8;
      }
      while ( v9 );
      result = v8 + v2;
      break;
    case 5u:
      v24 = 20;
      v25 = 5381;
      do
      {
        v26 = *((unsigned __int8 *)v->pNext + --v24);
        v25 = v26 + 65599 * v25;
      }
      while ( v24 );
      result = v25 + v2;
      break;
    case 7u:
      LODWORD(cv) = v->pPrev;
      v12 = 5381;
      v13 = 4;
      do
      {
        v14 = *((unsigned __int8 *)&retaddr + v13-- + 3);
        v12 = v14 + 65599 * v12;
      }
      while ( v13 );
      v15 = 5381;
      v16 = 4;
      do
      {
        v17 = (unsigned __int8)*(&v36 + v16--);
        v15 = v17 + 65599 * v15;
      }
      while ( v16 );
      result = (v12 ^ v15) + v2;
      break;
    case 0xAu:
      pNext = (Scaleform::GFx::AS3::Value::V1U)v->pNext;
      if ( !pNext.VInt )
        goto LABEL_28;
      result = (*(_DWORD *)(pNext.VInt + 16) & 0xFFFFFF) + v2;
      break;
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v->pNext )
      {
        v27 = 5381;
        v28 = 4;
        do
        {
          v29 = *((unsigned __int8 *)&retaddr + v28-- + 3);
          v27 = v29 + 65599 * v27;
        }
        while ( v28 );
        result = v27 + v2;
      }
      else
      {
LABEL_28:
        result = (int)v->__vftable & 0x1F;
      }
      break;
    case 0x10u:
      v30 = 20;
      v31 = 5381;
      do
      {
        v32 = *((unsigned __int8 *)v->pNext + --v30);
        v31 = v32 + 65599 * v31;
      }
      while ( v30 );
      v33 = 5381;
      v34 = 4;
      do
      {
        v35 = *((unsigned __int8 *)&retaddr + v34-- + 3);
        v33 = v35 + 65599 * v33;
      }
      while ( v34 );
      v3 = v31 ^ v33;
      goto LABEL_34;
    case 0x11u:
      LODWORD(cv) = v->pPrev;
      v18 = 5381;
      v19 = 4;
      do
      {
        v20 = *((unsigned __int8 *)&retaddr + v19-- + 3);
        v18 = v20 + 65599 * v18;
      }
      while ( v19 );
      v21 = 5381;
      v22 = 4;
      do
      {
        v23 = (unsigned __int8)*(&v36 + v22--);
        v21 = v23 + 65599 * v21;
      }
      while ( v22 );
      result = (v18 ^ v21) + v2;
      break;
    default:
LABEL_34:
      result = v3 + v2;
      break;
  }
  return result;
}
