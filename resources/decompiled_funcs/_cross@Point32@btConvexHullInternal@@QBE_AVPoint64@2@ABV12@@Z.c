btConvexHullInternal::Point64 *__userpurge btConvexHullInternal::Point32::cross@<eax>(
        const btConvexHullInternal::Point32 *b@<eax>,
        _QWORD *a2@<ecx>,
        btConvexHullInternal::Point32 *this)
{
  int y; // ebx
  int x; // esi
  int z; // ebp
  int v6; // edi
  int v8; // [esp+10h] [ebp-4h]
  int thisa; // [esp+18h] [ebp+4h]

  y = b->y;
  x = b->x;
  z = this->z;
  v6 = this->x;
  v8 = this->y;
  thisa = b->z;
  *a2 = thisa * v8 - y * z;
  a2[1] = z * x - thisa * v6;
  a2[2] = y * v6 - v8 * x;
  return (btConvexHullInternal::Point64 *)a2;
}
