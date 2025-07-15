void __userpurge survarium::flash_value::SetElement(
        survarium::flash_value *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int idx,
        survarium::flash_value *value)
{
  (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(*(_DWORD *)*a2 + 52))(
    *a2,
    a2[2],
    idx,
    value);
}


void __userpurge survarium::flash_value::SetElement(
        survarium::flash_value *this@<eax>,
        const char *value@<ecx>,
        unsigned int idx)
{
  int v3; // ecx
  int v4; // [esp-Ch] [ebp-30h]
  Scaleform::GFx::Value v5; // [esp+8h] [ebp-1Ch] BYREF

  v5.pObjectInterface = 0;
  v5.mValue.IValue = (int)value;
  v3 = *(_DWORD *)this->body;
  v4 = *(_DWORD *)&this->body[8];
  v5.Type = VT_String;
  (*(void (__thiscall **)(int, int, unsigned int, Scaleform::GFx::Value *))(*(_DWORD *)v3 + 52))(v3, v4, idx, &v5);
  Scaleform::GFx::Value::~Value(&v5);
}
