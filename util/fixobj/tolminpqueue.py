import math

# @class tolminpqueue
# @brief Minimum (within a tolerance) priority queue (numeric only currently)..
# The functionality of this class is exactly the same as for a minimum priority
# queue, however an additional tolerance paramater can be specified to functions
# instead of requiring two values to be exactly equal.
class tolminpqueue:
    # @class _tnode
    # @brief Tolerance node.
    # A node in a tolminpqueue (just has a tolerance paramater that you can
    # specify to fucntions.  Exact equality is also possible.
    class _tnode:
        # @brief Constructor.
        # @param d The data for this node (IT'S A LIST!!!).
        # @param r The right node for this node.
        # @param l The left node for this node.
        def __init__(self, d = None, r = None, l = None):
            self.data = d
            self.right = r
            self.left = l
            if r is not None and l is not None:
                self.weight = r.weight + l.weight
            else:
                self.weight = 0.0

        # @brief Check this node for equality with another node.
        # @param rhs The other node to check with this node for equality.
        # @param tol The tolerance to use (the absolute value of tol is used,
        #            and the default value is 0.0)).
        def equals_tol(self, rhs, tol = 0.0):
            union = (self.data + rhs.data).sort()
            return math.fabs(union.max() - union.min()) <= math.fabs(tol)

        # @brief Check for exact equality.
        # @param rhs The other node to check for equality with
        def __equals__(self, rhs):
            return equals_tol(rhs, 0.0)

        # @brief Insert a node given a tolerance.
        # @param n The node to insert.
        # @param tol The tolerance to use (default 0.0).
        def insert_tol(self, n, rhs)

        # @brief Insert a node exactly (tolerance 0.0).
        # @param n The node to insert.
        def insert(self, n)

    def __init__(self):
        self.
