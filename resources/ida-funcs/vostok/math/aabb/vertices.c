void __usercall vostok::math::aabb::vertices(vostok::math::aabb *this@<ecx>, int a2@<eax>)
{
  __int64 v2; // [esp+4h] [ebp-8h]
  __int64 v3; // [esp+4h] [ebp-8h]
  __int64 v4; // [esp+4h] [ebp-8h]
  __int64 v5; // [esp+4h] [ebp-8h]

  v2 = *(_QWORD *)(a2 + 4);
  this->min.x = *(float *)a2;
  *(_QWORD *)&this->min.elements[1] = v2;
  LODWORD(v2) = *(_DWORD *)(a2 + 4);
  HIDWORD(v2) = *(_DWORD *)(a2 + 20);
  this->max.x = *(float *)a2;
  *(_QWORD *)&this->max.elements[1] = v2;
  LODWORD(v2) = *(_DWORD *)(a2 + 16);
  HIDWORD(v2) = *(_DWORD *)(a2 + 8);
  this[1].min.x = *(float *)a2;
  *(_QWORD *)&this[1].min.elements[1] = v2;
  v3 = *(_QWORD *)(a2 + 16);
  this[1].max.x = *(float *)a2;
  *(_QWORD *)&this[1].max.elements[1] = v3;
  v4 = *(_QWORD *)(a2 + 4);
  this[2].min.x = *(float *)(a2 + 12);
  *(_QWORD *)&this[2].min.elements[1] = v4;
  LODWORD(v4) = *(_DWORD *)(a2 + 4);
  HIDWORD(v4) = *(_DWORD *)(a2 + 20);
  this[2].max.x = *(float *)(a2 + 12);
  *(_QWORD *)&this[2].max.elements[1] = v4;
  LODWORD(v4) = *(_DWORD *)(a2 + 16);
  HIDWORD(v4) = *(_DWORD *)(a2 + 8);
  this[3].min.x = *(float *)(a2 + 12);
  *(_QWORD *)&this[3].min.elements[1] = v4;
  v5 = *(_QWORD *)(a2 + 16);
  this[3].max.x = *(float *)(a2 + 12);
  *(_QWORD *)&this[3].max.elements[1] = v5;
}
