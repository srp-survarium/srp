__int64 __userpurge btConvexHullInternal::Point32::dot@<edx:eax>(
        const btConvexHullInternal::Point64 *b@<esi>,
        btConvexHullInternal::Point32 *this)
{
  return this->x * b->x + this->y * b->y + this->z * b->z;
}
