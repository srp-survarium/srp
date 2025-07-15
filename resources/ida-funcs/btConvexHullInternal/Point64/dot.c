__int64 __userpurge btConvexHullInternal::Point64::dot@<edx:eax>(
        const btConvexHullInternal::Point64 *b@<esi>,
        btConvexHullInternal::Point64 *this)
{
  return b->x * this->x + b->y * this->y + b->z * this->z;
}
