void __usercall vostok::math::aabb::vertices(vostok::math::aabb *this@<ecx>, __int64 *a2@<eax>)
{
  float v2; // edx
  float v3; // edx
  float v4; // edx
  float v5; // edx
  float v6; // edx
  float v7; // edx
  float v8; // edx
  float v9; // eax
  __int64 v10; // [esp+0h] [ebp-Ch]
  float v11; // [esp+8h] [ebp-4h]

  v10 = *a2;
  v11 = *((float *)a2 + 2);
  v2 = v11;
  *(_QWORD *)&this->min.x = v10;
  this->min.z = v2;
  v10 = *a2;
  v11 = *((float *)a2 + 5);
  v3 = v11;
  *(_QWORD *)&this->max.x = v10;
  this->max.z = v3;
  LODWORD(v10) = *(_DWORD *)a2;
  HIDWORD(v10) = *((_DWORD *)a2 + 4);
  v11 = *((float *)a2 + 2);
  v4 = v11;
  *(_QWORD *)&this[1].min.x = v10;
  this[1].min.z = v4;
  LODWORD(v10) = *(_DWORD *)a2;
  HIDWORD(v10) = *((_DWORD *)a2 + 4);
  v11 = *((float *)a2 + 5);
  v5 = v11;
  *(_QWORD *)&this[1].max.x = v10;
  this[1].max.z = v5;
  LODWORD(v10) = *((_DWORD *)a2 + 3);
  HIDWORD(v10) = *((_DWORD *)a2 + 1);
  v11 = *((float *)a2 + 2);
  v6 = v11;
  *(_QWORD *)&this[2].min.x = v10;
  this[2].min.z = v6;
  LODWORD(v10) = *((_DWORD *)a2 + 3);
  HIDWORD(v10) = *((_DWORD *)a2 + 1);
  v11 = *((float *)a2 + 5);
  v7 = v11;
  *(_QWORD *)&this[2].max.x = v10;
  this[2].max.z = v7;
  v10 = *(__int64 *)((char *)a2 + 12);
  v11 = *((float *)a2 + 2);
  v8 = v11;
  *(_QWORD *)&this[3].min.x = v10;
  this[3].min.z = v8;
  v10 = *(__int64 *)((char *)a2 + 12);
  v11 = *((float *)a2 + 5);
  v9 = v11;
  *(_QWORD *)&this[3].max.x = v10;
  this[3].max.z = v9;
}
