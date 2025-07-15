void __cdecl Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>>(
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  signed int v1; // esi
  signed int v2; // ebp
  int v3; // ebx
  signed int v4; // edi

  v1 = arr->Data.Size - 1;
  v2 = 0;
  if ( v1 > 0 )
  {
    v3 = 0;
    v4 = v1;
    do
    {
      Scaleform::GFx::AS3::Value::Swap(&arr->Data.Data[v3], &arr->Data.Data[v4]);
      ++v2;
      --v1;
      ++v3;
      --v4;
    }
    while ( v2 < v1 );
  }
}
