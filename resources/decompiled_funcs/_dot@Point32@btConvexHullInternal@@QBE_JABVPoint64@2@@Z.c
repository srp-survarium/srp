__int64 __usercall btConvexHullInternal::Point32::dot@<edx:eax>(
        btConvexHullInternal::Point32 *this@<edi>,
        const btConvexHullInternal::Point64 *b@<esi>)
{
  return this->x * b->x + this->y * b->y + this->z * b->z;
}
