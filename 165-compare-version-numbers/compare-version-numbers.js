/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const arr1 = version1.split('.').map(el=>(Number(el)));
    const arr2 = version2.split('.').map(el=>(Number(el)));
    const n=Math.max(arr1.length,arr2.length);
    
    for(let i=0; i<n; i++){
        if(arr1[i]==undefined){
            if(arr2[i]!=0) return -1;
        }
        else if(arr2[i]==undefined){
            if(arr1[i]!=0) return 1;
        }
        else{
            if(arr1[i]>arr2[i]) return 1;
            else if(arr2[i]>arr1[i]) return -1;
        }
    }
    return 0;
};