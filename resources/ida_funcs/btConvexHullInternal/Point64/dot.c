__int64 __usercall btConvexHullInternal::Point64::dot@<edx:eax>(
        btConvexHullInternal::Point64 *this@<edi>,
        const btConvexHullInternal::Point64 *b@<esi>)
{
  return b->x * this->x + b->y * this->y + b->z * this->z;
}
