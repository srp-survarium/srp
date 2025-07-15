void __userpurge survarium::flash_movie::SetViewport(
        survarium::flash_movie *this@<ecx>,
        unsigned int output_window_width@<eax>,
        int output_window_height)
{
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  int v7; // edx
  survarium::flash_value *v8; // ecx
  Scaleform::GFx::Value *v9; // esi
  int i; // edi
  Scaleform::GFx::Viewport v11; // [esp+Ch] [ebp-64h] BYREF
  survarium::flash_value v12; // [esp+40h] [ebp-30h] BYREF
  _BYTE v13[24]; // [esp+58h] [ebp-18h] BYREF
  char vars0; // [esp+70h] [ebp+0h] BYREF

  this->m_output_width = output_window_width;
  this->m_output_height = output_window_height;
  Scaleform::GFx::Viewport::Viewport(
    &v11,
    output_window_width,
    output_window_height,
    0,
    0,
    output_window_width,
    output_window_height,
    0);
  v5 = &v12;
  do
  {
    survarium::flash_value::flash_value(v5);
    v5 = v6 + 1;
  }
  while ( v7 - 1 >= 0 );
  survarium::flash_value::SetUInt(v5, (int)&v12, output_window_width);
  survarium::flash_value::SetUInt(v8, (int)v13, output_window_height);
  Scaleform::GFx::Movie::Invoke((Scaleform::GFx::Movie *)&stru_823330, 0, v12.body, 2);
  this->m_movie->SetViewport(this->m_movie, &v11);
  v9 = (Scaleform::GFx::Value *)&vars0;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v9);
}
