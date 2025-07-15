void __userpurge survarium::options_tab::initialize_data(
        survarium::options_tab *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie)
{
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  int v6; // edx
  survarium::flash_value *v7; // ecx
  bool v8; // zf
  unsigned int v9; // ebx
  int v10; // ecx
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_movie *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  Scaleform::GFx::Value *v17; // esi
  int i; // edi
  survarium::flash_value v19; // [esp+10h] [ebp-84h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+28h] [ebp-6Ch] BYREF
  _BYTE v21[24]; // [esp+40h] [ebp-54h] BYREF
  char v22; // [esp+58h] [ebp-3Ch] BYREF
  survarium::flash_value v23; // [esp+5Ch] [ebp-38h] BYREF
  survarium::flash_value value; // [esp+74h] [ebp-20h] BYREF
  unsigned __int8 v25; // [esp+8Fh] [ebp-5h]

  v4 = &v19;
  do
  {
    survarium::flash_value::flash_value(v4);
    v4 = v5 + 1;
  }
  while ( v6 - 1 >= 0 );
  survarium::flash_value::SetUInt(v4, (int)&v19, *(_DWORD *)(a2 + 8));
  survarium::flash_value::SetBoolean(v7, (int)v21, 1);
  Scaleform::GFx::Movie::CreateArray(movie->m_object->movie->m_movie, &pvalue);
  v8 = *(_BYTE *)(a2 + 4) == 0;
  v25 = 0;
  if ( !v8 )
  {
    do
    {
      v9 = v25;
      v10 = *(_DWORD *)(*(_DWORD *)a2 + 4 * v25);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(v10);
      m_object = movie->m_object;
      *(_DWORD *)v23.body = 0;
      *(_DWORD *)&v23.body[4] = 0;
      survarium::flash_movie::CreateObject(
        v12,
        (survarium::flash_value *)m_object->movie,
        (Scaleform::GFx::Value *)&v23);
      *(_DWORD *)value.body = 0;
      *(_DWORD *)&value.body[4] = 0;
      survarium::flash_value::SetUInt(v13, (int)&value, v9);
      survarium::flash_value::SetMember(v14, &v23, "id", &value);
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *))(**(_DWORD **)(*(_DWORD *)a2 + 4 * v9) + 12))(
        *(_DWORD *)(*(_DWORD *)a2 + 4 * v9),
        &value);
      survarium::flash_value::SetMember(v15, &v23, "value", &value);
      survarium::flash_value::SetElement(v16, &pvalue, v9, &v23);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v23);
      ++v25;
    }
    while ( v25 < *(_BYTE *)(a2 + 4) );
  }
  Scaleform::GFx::Movie::Invoke(
    movie->m_object->movie->m_movie,
    "root.set_values",
    0,
    (const Scaleform::GFx::Value *)&v19,
    3u);
  v17 = (Scaleform::GFx::Value *)&v22;
  for ( i = 2; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v17);
}
