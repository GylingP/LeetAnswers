typedef struct numsNode {
    int* nums;
    int size;
    int left;
    int right;
} numsNode, *numsNodePtr;

void initNode(numsNodePtr p, int* nums, int size, int left, int right) {
    p->nums = nums;
    p->size = size;
    p->left = left;
    p->right = right;
    return;
}

double getMid(int* nums, int size, int offset) {
    return (nums[(size - 1) / 2 - offset] + nums[size / 2 - offset]) / 2.0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    // if (nums1Size == 0)
    //     return getMid(nums2, nums2Size);
    // if (nums2Size == 0)
    //     return getMid(nums1, nums1Size);
    numsNode node1, node2;
    numsNodePtr nodeLittle = &node1, nodeLarge = &node2;
    initNode(&node1, nums1, nums1Size, 0, nums1Size - 1);
    initNode(&node2, nums2, nums2Size, 0, nums2Size - 1);
    while (1) {
        if (nodeLittle->right < nodeLittle->left)
            return getMid(nodeLarge->nums + nodeLarge->left,
                          nodeLarge->right - nodeLarge->left + 1, 0);
        if (nodeLarge->right < nodeLarge->left)
            return getMid(nodeLittle->nums + nodeLittle->left,
                          nodeLittle->right - nodeLittle->left + 1, 0);
        if (nodeLittle->nums[nodeLittle->left] >
            nodeLarge->nums[nodeLarge->left]) {
            numsNodePtr p = nodeLittle;
            nodeLittle = nodeLarge;
            nodeLarge = p;
        }
        if (nodeLittle->nums[nodeLittle->right] <=
            nodeLarge->nums[nodeLarge->left]) {
            int sizeLittle = nodeLittle->right - nodeLittle->left + 1;
            int sizeLarge = nodeLarge->right - nodeLarge->left + 1;
            if (sizeLittle == sizeLarge)
                return (nodeLittle->nums[nodeLittle->right] +
                        nodeLarge->nums[nodeLarge->left]) /
                       2.0;
            if (sizeLittle < sizeLarge)
                return getMid(nodeLarge->nums + nodeLarge->left,
                              sizeLittle + sizeLarge, sizeLittle);
            else
                return getMid(nodeLittle->nums + nodeLittle->left,
                              sizeLittle + sizeLarge, 0);
        }
        if (nodeLittle->nums[nodeLittle->right] >=
            nodeLarge->nums[nodeLarge->right]) {
            nodeLittle->right--;
            nodeLittle->left++;

        } else {
            nodeLarge->right--;
            nodeLittle->left++;
        }
    }
}