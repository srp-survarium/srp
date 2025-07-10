char __usercall btGjkEpaSolver2::SignedDistance@<al>(
        const btTransform *wtrs0@<ecx>,
        const gjkepa2_impl::MinkowskiDiff *guess@<eax>,
        const btConvexShape *shape0,
        const btConvexShape *shape1,
        const btTransform *wtrs1,
        btGjkEpaSolver2::sResults *results)
{
  if ( btGjkEpaSolver2::Distance(shape0, wtrs0, shape1, wtrs1, (const btVector3 *)guess, results) )
    return 1;
  else
    return btGjkEpaSolver2::Penetration(shape0, wtrs0, shape1, wtrs1, guess, results, 0);
}
