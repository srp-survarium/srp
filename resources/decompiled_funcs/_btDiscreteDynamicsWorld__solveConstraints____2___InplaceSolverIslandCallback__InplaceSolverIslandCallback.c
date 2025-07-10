void __userpurge btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::InplaceSolverIslandCallback(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this@<ecx>,
        int a2@<eax>,
        btConstraintSolver *solverInfo,
        btTypedConstraint **solver,
        btTypedConstraint **sortedConstraints,
        btIDebugDraw *numConstraints,
        btStackAlloc *debugDrawer,
        btDispatcher *stackAlloc,
        btDispatcher *dispatcher)
{
  *(_DWORD *)(a2 + 4) = this;
  *(_DWORD *)(a2 + 8) = solverInfo;
  *(_DWORD *)(a2 + 12) = solver;
  *(_DWORD *)(a2 + 16) = sortedConstraints;
  *(_DWORD *)(a2 + 20) = numConstraints;
  *(_DWORD *)(a2 + 24) = debugDrawer;
  *(_DWORD *)(a2 + 28) = stackAlloc;
  *(_DWORD *)a2 = &`btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::`vftable';
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_BYTE *)(a2 + 48) = 1;
  *(_BYTE *)(a2 + 68) = 1;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 88) = 1;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
}
